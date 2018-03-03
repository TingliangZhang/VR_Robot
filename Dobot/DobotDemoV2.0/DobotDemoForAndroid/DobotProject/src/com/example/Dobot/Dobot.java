package com.example.Dobot;

import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.util.UUID;
import Dobot.demo.R;

import Dobot.Params.IOMultiplexing;
import Dobot.Params.JOGCmdParams;
import Dobot.Params.JOGJointParams;
import Dobot.Params.PTPCmd;
import Dobot.Params.PTPJointParams;
import Dobot.Params.TagPose;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothProfile;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

public class Dobot {
	
	private   Context  context = null ;    
	private   DataReceiveListener   DataListener;
	
	private   ArrayList<byte[]>  CommandQueue0= new ArrayList<byte[]>(); //即时命令队列
	private   ArrayList<byte[]>  CommandQueue1= new ArrayList<byte[]>();  //队列命令队列
	
	private boolean  mConnected = false ;
	private String   mDeviceAddress = "" ;
		
    private BluetoothManager             mBluetoothManager =  null;
    private BluetoothAdapter             mBluetoothAdapter =  null;
    private BluetoothDevice              mBluetoothDevice  =  null;
    private static  BluetoothGatt        mBluetoothGatt    =  null;
    private BluetoothGattService         mBluetoothSelectedService =  null;
    private List<BluetoothGattService>   mBluetoothGattServices    =  null;	
    
    private static final UUID    Server_UUID  =   UUID.fromString("0003CDD0-0000-1000-8000-00805f9b0131"); //服务的UUID
    private static final UUID    Write_UUID   =   UUID.fromString("0003CDD2-0000-1000-8000-00805f9b0131"); //写数据的UUID
    private static final UUID    Read_UUID    =   UUID.fromString("0003CDD1-0000-1000-8000-00805f9b0131"); //读数据的UUIO(NOTIFY)
    
    private Handler mTimerHandler = new Handler();
    private boolean mTimerEnabled = false;
    
    
    private static final int RSSI_UPDATE_TIME_INTERVAL = 1500; //  1.5 seconds  读取信号强度Rssi的周期
    private DobotCallbacks mUiCallback = null; 
    private static final DobotCallbacks NULL_CALLBACK = new DobotCallbacks.Null(); 
      
    //Search  Dialog
    private  ListView listdevice;//dialog中显示蓝牙设备的listView
    private  ArrayAdapter<String> MylistViewAdapter;//向 ListView 中填充数据
    private  List<String> arrayBluetooth = new ArrayList<String>();
    private  Button    cancelbut, searchbut;
 	private  Dialog    dialog;   

 	private   Boolean   mScanning=false;
    private  static    final long SCAN_PERIOD = 3000; //  ble扫描时间10s
 	
    private  static List<DataReceiveListener>  LISTENER = new ArrayList<DataReceiveListener>();
    private  static List<DataReceiveListener>  LISTENER1 = new ArrayList<DataReceiveListener>();
 	
 	//返回指令的三个状态
	public static  int      CMDStatus=0 ;  //命令的返回状态  
 	public static final int Normal =1;
 	public static final int Error =2;
 	public static final int TimeOut =3;
 	
    
    Boolean  BleIsIdle = true; 
 	
 	//超时计时器
    private    Timer       timer;
    private    TimerTask   task ;
    private    Boolean     isQueuedTimeOut ;
    
    //
 	private int  CmdLeftSpace;  //发送队列命令前查询的 CmdLeftSpace长度
	private Boolean  ReadLeftSpaceFlag=false;
 	  
 	  //接收解析数据用
	private static  byte  receive[] = null;
      int   n=0; //要n次才能接收完一帧完整的数据
      int   k=0; //
      int   offset=0;
      
      Boolean  isFull=false;
      
      
      ProgressDialog progress ;
      
      public Dobot(Context  context,DobotCallbacks callback) {
    	  
		   this.context=context;
		   
		   mUiCallback = callback;
		   
		  if(mUiCallback == null)     mUiCallback = NULL_CALLBACK;
	  }

      
      private BluetoothManager           getManager() { return mBluetoothManager; } 
      private BluetoothAdapter           getAdapter() { return mBluetoothAdapter; }
      private BluetoothDevice            getDevice()  { return mBluetoothDevice;  }
      private BluetoothGatt              getGatt()    { return mBluetoothGatt;    }
      private BluetoothGattService       getCachedService()  { return mBluetoothSelectedService; }
      private List<BluetoothGattService> getCachedServices() { return mBluetoothGattServices;    }
      private boolean                    isConnected() { return mConnected; }

	/* run test and check if this device has BT and BLE hardware available */
    private boolean checkBleHardwareAvailable() {    
		
		final BluetoothManager manager = (BluetoothManager) context.getSystemService(Context.BLUETOOTH_SERVICE);
		if(manager == null) return false;
		 
		final BluetoothAdapter adapter = manager.getAdapter();
		if(adapter == null) return false;
	
		boolean hasBle = context.getPackageManager().hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE);		
		
		return hasBle;
	}    

	
    private boolean isBtEnabled() {
		final BluetoothManager manager = (BluetoothManager) context.getSystemService(Context.BLUETOOTH_SERVICE);
		if(manager == null) return false;
		
		final BluetoothAdapter adapter = manager.getAdapter();
		if(adapter == null) return false;
		
		return adapter.isEnabled();
	}
	
		
	/* start scanning for BT LE devices around */
    private void startScanning() {
	    mBluetoothAdapter.startLeScan(mDeviceFoundCallback);
    }
	
	/* stops current scanning */
    private void stopScanning() {
	    mBluetoothAdapter.stopLeScan(mDeviceFoundCallback);			
	}
	
	
    /* initialize BLE and get BT Manager & Adapter */
    public boolean initialize() {
    	
        if (mBluetoothManager == null) {
             mBluetoothManager = (BluetoothManager) context.getSystemService(Context.BLUETOOTH_SERVICE);
           if (mBluetoothManager == null) {
                  return false;
                }
          }
        
        if(mBluetoothAdapter == null)     mBluetoothAdapter = mBluetoothManager.getAdapter();
        if(mBluetoothAdapter == null)     {  return false; }
       
        return true;    	
    }
    
    
    private void  ShowProgress(){
    	
    	if(progress!=null)  progress=null;
    	
    	  progress= new ProgressDialog(context);  
    	  progress.setProgressStyle(ProgressDialog.STYLE_SPINNER);// 设置进度条的形式为圆形转动的进度条     	  
    	  progress.setCancelable(true);// 设置是否可以通过点击Back键取消  
    	  progress.setCanceledOnTouchOutside(false);// 设置在点击Dialog外是否取消Dialog进度条  
          progress.show();
    	
      }
    
 private void  DismissProgress(){
    	
    	if(progress!=null)  
                progress.dismiss();;
           progress=null;
    	}
    
    
    
    
    /* connect to the device with specified address */
 private boolean connect(final String deviceAddress) {
    	
    	if (mBluetoothAdapter == null || deviceAddress == null)   	return false;
            mDeviceAddress  =  deviceAddress;
        
                // check if we need to connect from scratch or just reconnect to previous device
            if(mBluetoothGatt != null && mBluetoothGatt.getDevice().getAddress().equals(deviceAddress))  { 
               // just reconnect 如果 mBluetoothGatt存在 判断Gatt中的存在的MAC  是否和选择的BLE的MAC相同，如果是同一个设备， 直接重新连接
          	      return mBluetoothGatt.connect(); 
          	   }  
          
            else { //BluetoothGatt 已关闭不存在   
                 //mBluetoothGatt不存在   从搜索到的BLE中通过MAC连接
        	     // connect from scratch
                 // get BluetoothDevice object for specified address
                    mBluetoothDevice = mBluetoothAdapter.getRemoteDevice(mDeviceAddress);
                if (mBluetoothDevice == null) {
                  // we got wrong address - that device is not available!
                     return false;
                   }
                // connect with remote device
            	   mBluetoothGatt = mBluetoothDevice.connectGatt(context, false, mBleCallback);//
            
              }  
            
            return true;   
    }  
    
    
    /* disconnect the device. It is still possible to reconnect to it later with this Gatt client */
    private void diconnect() {
    	if(mBluetoothGatt != null) mBluetoothGatt.disconnect();
    	   mUiCallback.DobotDisconnected(mBluetoothGatt, mBluetoothDevice);
    }
      
    /* close GATT client completely */
    public void close() {
    	if(mBluetoothGatt != null)
    		{
    		//  mBluetoothGatt.disconnect();  //执行此句后  会立刻 DISCONNECTED 回调 检测到蓝牙断开
    		    mBluetoothGatt.close();       //此句会断开蓝牙连接 关闭BluetoothGatt 但不会进行蓝牙连接断开的回调
    		}
    	
    	   mBluetoothGatt = null;
    	   
    	   CommandQueue0.clear();
    	   
    	   CommandQueue1.clear();
    	   
    	   LISTENER.clear();
    	   
    	   LISTENER1.clear();
    }    
    
    /* request new RSSi value for the connection*/
    private void readPeriodicalyRssiValue(final boolean repeat) {
    	    mTimerEnabled = repeat;
    	  // check if we should stop checking RSSI value
    	   if(mConnected == false || mBluetoothGatt == null || mTimerEnabled == false) {
    		    mTimerEnabled = false;
    		    return;
    	     }
    	
    	   mTimerHandler.postDelayed(new Runnable() {
			@Override
			public void run() {
				if(mBluetoothGatt == null || mBluetoothAdapter == null || mConnected == false)
				{
				   mTimerEnabled = false;	
				   return;
				}
				
				// request RSSI value
				mBluetoothGatt.readRemoteRssi();
				
				// add call it once more in the future
				readPeriodicalyRssiValue(mTimerEnabled);  // 多次调用    不断的调用readPeriodicalyRssiValue()方法 读取RSSI
			}
    	}, RSSI_UPDATE_TIME_INTERVAL );
    }    
    
    
    /* starts monitoring RSSI value */
    private void startMonitoringRssiValue() {
           readPeriodicalyRssiValue(true);
    }
    
    
    /* stops monitoring of RSSI value */
    private void stopMonitoringRssiValue() {
    	
    	readPeriodicalyRssiValue(false);
    	
    }
    
    /* request to discover all services available on the remote devices
     * results are delivered through callback object */
    private void startServicesDiscovery() {
    	if(mBluetoothGatt != null) mBluetoothGatt.discoverServices();
    }
    
    
    /* gets services and calls UI callback to handle them
     * before calling getServices() make sure service discovery is finished! */
    private void getSupportedServices() {
    	
    	Log.i("ble", "发现支持的服务   ") ;//
    	
    	if(mBluetoothGattServices != null && mBluetoothGattServices.size() > 0)  mBluetoothGattServices.clear();
    	// keep reference to all services in local array:
        if(mBluetoothGatt != null) mBluetoothGattServices = mBluetoothGatt.getServices();
        
        writerCharateristics() ;     //获取服务后 开始写 Charateristics
       
        // mUiCallback.uiAvailableServices(mBluetoothGatt, mBluetoothDevice, mBluetoothGattServices);
    }
      
    private void writerCharateristics(){
    	
    	BluetoothGattService  bgs  =  mBluetoothGatt.getService(Server_UUID) ; //Service UUID
      
    	setNotificationForCharacteristic(bgs.getCharacteristic(Read_UUID), true);  //给一个特性设置通知, 当远程BLE设备的该特性发送变化，回调函数onCharacteristicChanged( ))被触发
	       
		final BluetoothGattCharacteristic mCharacteristic  = bgs.getCharacteristic(Write_UUID) ;//Characteristic  UUID
	    
     	new Thread(){
			
    		public void run(){
			
    			while(mBluetoothGatt !=  null){
    				   				
    				//优先发送即时命令
    		     if(CommandQueue0.size()>0){
    					
    		    	           while(!BleIsIdle);  
              	         
    		    	           TimeOutTimer(); //启动超时定时器
    		    	 
    		    	           //Log.i("64", "CommandQueue0 size  "+CommandQueue0.size()); 
    		    	 
    		    	           for(int k=0;k< Util.SendPackage(CommandQueue0.get(0)).size();k++){
				    		  
                                      mCharacteristic.setValue(Util.SendPackage(CommandQueue0.get(0)).get(k)); 
				    		       
				    		       if (mBluetoothGatt != null)
	 						           mBluetoothGatt.writeCharacteristic(mCharacteristic);		    		         
				    		           isQueuedTimeOut=false;
				    		           BleIsIdle=false;//开始发送数据  BLE处于忙碌状态    在接收回调中 会将BleIsIdle设置位true
				    		    	 
				    		           
				    		    	   try {Thread.sleep(50);} 
	 				                   catch (InterruptedException e) {e.printStackTrace();} 
				    		         }
    		    	                   Log.i("64", ""+"发送即时指令  id=="+(CommandQueue0.get(0)[3]&0xff)); //打印指令的id
    		    	                   
				    	               CommandQueue0.remove(0);
				          }  
    				
    				
    				 //及时命令发送完了才发送队列命令    即时命令队列中没有数据才能执行队列命令
    		     if((CommandQueue1.size()>0)&(CommandQueue0.size()==0)){
    			
    		    	 
    		    	if(ReadLeftSpaceFlag==false){    //避免重复读
    		    		
    		    	isFull=true;
    		    		//读可存放的剩余指令数量
      		         GetQueuedCmdLeftSpace(new  DataReceiveListener() { 
  					  @Override
  					  public void OnReceive() {
  						// TODO Auto-generated method stub
  						    
  						    CmdLeftSpace = GetLeftSpace();  //
  						    
  						    if(CmdLeftSpace>0)    isFull=false;
  						    else                  isFull=true;
  						    
  						    ReadLeftSpaceFlag=true;
  						    
  						    Log.i("64", "CmdLeftSpace--"+CmdLeftSpace);
  					       }
  				        });
    		        }
    		    	  
    		            
    		    	
    		    	 if(isFull==false){       //  剩余指令空间大于0  可以继续发送队列指令
    		    		
    		    		isFull=true;
    		    		
    		    		ReadLeftSpaceFlag=false;
    		    		
    		    		 while(!BleIsIdle);  
              	         
		    	         TimeOutTimer(); //启动超时定时器
    		    		
    		    		for(int k=0;k<Util.SendPackage(CommandQueue1.get(0)).size();k++){
    		    			   
    		    			mCharacteristic.setValue(Util.SendPackage(CommandQueue1.get(0)).get(k)); 
     					    	
    		    			if (mBluetoothGatt != null)  mBluetoothGatt.writeCharacteristic(mCharacteristic);
    		    			    
    		    			    isQueuedTimeOut=true;
		    		            
    		    			    BleIsIdle=false;//开始发送数据  BLE处于忙碌状态    在接收回调中 会将BleIsIdle设置位true
		    		    	 
    		    			    try {Thread.sleep(50);} catch (InterruptedException e) { e.printStackTrace(); } 
     					   }
    		    		        Log.i("64", ""+"发送队列指令  id=="+(CommandQueue1.get(0)[3]&0xff)); //打印指令的id
     					       
    		    		        CommandQueue1.remove(0); //发完后移除    
     					}
    		    	  
    		
    		    	   //
    				     
    		    	     /* for(int k=0;k<Util.SendPackage(CommandQueue1.get(0)).size();k++){
    				    	  
    				    	  while(!BleIsIdle);
    				    	  
					    	  mCharacteristic.setValue(Util.SendPackage(CommandQueue1.get(0)).get(k)); 
					    	
					    	  if (mBluetoothGatt != null)  mBluetoothGatt.writeCharacteristic(mCharacteristic);
					    	   isQueuedTimeOut=true;
					    	    BleIsIdle=false;
					    	    
					    	  try {Thread.sleep(1000);} catch (InterruptedException e) {  e.printStackTrace();  } 
					        }
					          CommandQueue1.remove(0); //发完后移除
                	    */

					}
    			}
			 }
		}.start() ;
    }
                
      
    /* get all characteristic for particular service and pass them to the UI callback */
    private void getCharacteristicsForService(final BluetoothGattService service) {
    	if(service == null) return;
    	
    	List<BluetoothGattCharacteristic> chars = null;       
    	
    	chars = service.getCharacteristics();   	
    	
    //	mUiCallback.uiCharacteristicForService(mBluetoothGatt, mBluetoothDevice, service, chars);
    	
    	mBluetoothSelectedService = service;   
    	
    }
    
    /* request to fetch newest value stored on the remote device for particular characteristic */
    private void requestCharacteristicValue(BluetoothGattCharacteristic ch) {
        if (mBluetoothAdapter == null || mBluetoothGatt == null) return;
        
            mBluetoothGatt.readCharacteristic(ch);
            //new value available will be notified in Callback Object
    }
 
    private void setNotificationForCharacteristic(BluetoothGattCharacteristic ch, boolean enabled) {
       
    	if (mBluetoothAdapter == null || mBluetoothGatt == null) return;
        
        boolean success = mBluetoothGatt.setCharacteristicNotification(ch, enabled);
        
        if(!success) {Log.e("------", "Seting proper notification status for characteristic failed!"); }
      
        BluetoothGattDescriptor descriptor = ch.getDescriptor(UUID.fromString("00002902-0000-1000-8000-00805f9b34fb"));
     
        if(descriptor != null) {
        	
        	byte[] val = enabled ? BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE : BluetoothGattDescriptor.DISABLE_NOTIFICATION_VALUE;
	      
        	descriptor.setValue(val);   
        	mBluetoothGatt.writeDescriptor(descriptor);   //
	      }
    }
       
    /* defines callback for scanning results */
    private BluetoothAdapter.LeScanCallback mDeviceFoundCallback = new BluetoothAdapter.LeScanCallback() {
        @Override
        public void onLeScan(final BluetoothDevice device, final int rssi, final byte[] scanRecord) {
        	//mUiCallback.DobotFound(device, rssi, scanRecord);
        	        
        }
    };	    
    
    
    
     /**
      * BLE回调
     */
    private final BluetoothGattCallback mBleCallback = new BluetoothGattCallback() {
        @Override
        public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState) {
           
        	if (newState == BluetoothProfile.STATE_CONNECTED) {
            	mConnected = true;
            	
            //	mUiCallback.uiDeviceConnected(mBluetoothGatt, mBluetoothDevice);
                mHandler.obtainMessage(2).sendToTarget(); //蓝牙连接成功
                
                scanLeDevice(false); //连接成功后关闭扫描
                
            	mBluetoothGatt.readRemoteRssi();
                
            	startServicesDiscovery();
            	
            	startMonitoringRssiValue();   //开始监听Rssi信号强度值
            	
            	Log.i("456","连接成功  返回码 "+status +"    "+newState) ;
            	
            }else if (newState == BluetoothProfile.STATE_DISCONNECTED) {
            	  
            	  mConnected = false;
            	  
            	  if(mBluetoothGatt != null){          //关闭对象  下次连接时重新创建
		    		  
	            	    mBluetoothGatt.close();       //此句会断开蓝牙连接 关闭BluetoothGatt 但不会进行蓝牙连接断开的回调
		    		    
		    		    mBluetoothGatt = null;
		    		    
		    		}
            	  
            	  //mUiCallback.uiDeviceDisconnected(mBluetoothGatt, mBluetoothDevice);
            	  
            	  mHandler.obtainMessage(3).sendToTarget(); //蓝牙连接断开
            	           
            	  Log.i("ble","连接断开  错误码  "+status +"    "+newState);
              }
        }
        

        @Override
        public void onServicesDiscovered(BluetoothGatt gatt, int status) {
            if (status == BluetoothGatt.GATT_SUCCESS) {
            	// now, when services discovery is finished, we can call getServices() for Gatt
            	
            	   Log.i("456","发现服务 ") ;
            	   getSupportedServices();  //服务发现结束后  启动写数据的线程
            	 
            }
        }
      
        @Override
        public void onCharacteristicRead(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status){
        	// we got response regarding our request to fetch characteristic value
            if (status == BluetoothGatt.GATT_SUCCESS) {
            	
            }
        }

        
       @Override
        public void onCharacteristicChanged(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic)
        {
        	
    	    // mHandler.obtainMessage(0).sendToTarget(); //
    	   //  mUiCallback.uiGotNotification(mBluetoothGatt, mBluetoothDevice, mBluetoothSelectedService, characteristic);
    	     
    	     byte  data[]= characteristic.getValue();
      	   
      	     if((data[0]==-86)&(data[1]==-86)){
      	        
      	            k=1;   
                    int   len = data[2]+4;        //返回一帧数据的总长度
                  //  receive=null;
                    receive = new byte[len];      //存放接收到的完整数据帧

                    if(len%20>0)    n = len/20 + 1;  //需要分包接收的次数
                    else            n = len/20 ; 
                 }   
      	     else{ 
      		        k++;
      	            offset=offset+20; 
      	         }

            System.arraycopy(data,0, receive, offset, data.length); // 数据包拼接成一帧完整的数据   
    	     
            if(k==n){   //  一帧数据接收完毕
      	   
        	       n=0; // 参数复位  
                   k=0; //
                   offset=0;
                   
                   if(CheckSum()==true){
                	 
                	   CMDStatus=1;
                	   Log.i("64", ""+"接受返回数据    id-"+(receive[3]&0xff)); 
                	   
                  }
                	  
                  else  { 
                	     CMDStatus=0;
                         Log.i("64", ""+"接受的数据不正确"); 
                  }
                	  
                  mHandler.obtainMessage(0).sendToTarget(); //一帧数据接收完毕  且完整
                   
                  BleIsIdle = true; //数据返回后  BLE处于空闲状态  可以开始发送下一条数据了
                  
                  if (timer != null) {  timer.cancel();timer=null;}
				  if (task != null)  {  task.cancel();task=null;  }
				  
				  
                   for(int kk=0;kk<receive.length;kk++)  { 
                	       Log.i("WW", ""+(receive[kk]&0XFF)); 
                	   }  
				}
        }
                  
            @Override
           public void onCharacteristicWrite(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status) {
        	
        	
        };
        
        
        @Override
        public void onReadRemoteRssi(BluetoothGatt gatt, int rssi, int status) {
        	if(status == BluetoothGatt.GATT_SUCCESS) {
        		// we got new value of RSSI of the connection, pass it to the UI
        		  Log.i("ble0", "Rssi  "+rssi) ;  
        	 }
         };
     };
             
      public  void  Connect(){
    	 
    	    scanLeDevice(true);  //开始扫描    在扫描回调中发现有指定名称的会自动连接 并停止扫描
       }
     
     
      private void showDialog() {  // 
 		
 		final LayoutInflater inflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
         View dialogview = inflater.inflate(R.layout.dialogview, null);

 		 Button cancelbut = (Button) dialogview.findViewById(R.id.cancelbut);
       
 		cancelbut.setOnClickListener(new OnClickListener() {
 			@Override
 			public void onClick(View v) {
 				 
 				//  scanLeDevice(false);//停止搜索
 				  dialog.dismiss();
 
 			 }
 		 });
 		
 		
 	    listdevice = (ListView) dialogview.findViewById(R.id.listdevice); //listview 显示搜到的蓝牙
 		listdevice.setCacheColorHint(0);
 		
 		arrayBluetooth.clear(); //清除上次搜索到的数据
 		

 	    MylistViewAdapter = new ArrayAdapter<String>(context,android.R.layout.simple_list_item_1, arrayBluetooth);
        
 		listdevice.setAdapter(MylistViewAdapter);   // private List<String>
 		
 		//listdevice.setOnItemClickListener(context);
 		listdevice.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				// TODO Auto-generated method stub

				 dialog.dismiss();
				 String  ble_mac=arrayBluetooth.get(position);//获取选中的item中的String内容   此处为BLE设备的 name 和 mac 地址组合成的字符串
				 ble_mac=ble_mac.substring(ble_mac.length()-17); //去掉组合字符串前的name 取出ble_mac字符串的后面的17位mac地址  
					
			     mBluetoothDevice  =  mBluetoothAdapter.getRemoteDevice(ble_mac); 
			     mBluetoothGatt    =  mBluetoothDevice.connectGatt(context,false, mBleCallback); //false  不自动连接
				 mScanning = false;  
				 scanLeDevice(false);   
			}
		});
 		
 		
 	    dialog = new Dialog(context, R.style.progress_dialog);
 		dialog.setContentView(dialogview);//dialog UI
 		dialog.show();		
 	}  
 	
	

     //开始BLE扫描  
        private void scanLeDevice(final boolean enable) {
         if (enable) {
             // Stops scanning after a pre-defined scan period.
          
        	 new  Handler().postDelayed(new Runnable() {    
                 @Override
                 public void run() {
                      mScanning = false;
                      mBluetoothAdapter.stopLeScan(mLeScanCallback); 
                     
                      if(mConnected==false)//
                         mUiCallback.DobotConnectTimeOut();   
                     
                      DismissProgress();
                  
                 }
             }, SCAN_PERIOD);

             mScanning = true;
             mBluetoothAdapter.startLeScan(mLeScanCallback);  
             ShowProgress(); 
         } else {
               mScanning = false;
               mBluetoothAdapter.stopLeScan(mLeScanCallback);  //
               DismissProgress();
         }
         
     }
     
        // BLE扫描结果回调
        private BluetoothAdapter.LeScanCallback mLeScanCallback = new BluetoothAdapter.LeScanCallback() {

            @Override
            public void onLeScan(final BluetoothDevice device, int rssi, byte[] scanRecord) {
                 String BleName = device.getName(); 
          	     String BleMac = device.getAddress() ;
                 String ss= BleName+"\n"+BleMac;  //组合BLE的name和mac 换行显示在listview的同一个item中
                
          	    /* if( !arrayBluetooth.contains(ss)){// ble会不断的扫描  可能多次扫到同一BLE设备   此处检测arrayBluetooth数组中是否包含扫描到的device
          		      arrayBluetooth.add(ss);//  
                      MylistViewAdapter.notifyDataSetChanged();//更新数据
                        Log.i("ble",device.getName()+"   "+device.getAddress() )	;	
				  }*/
          	     
                 if(BleName!=null){
                	 
                	 if(BleName.contains("USR-BLE100")){         	    	   
             	    	  mBluetoothDevice  =  mBluetoothAdapter.getRemoteDevice(BleMac); 
        			      mBluetoothGatt    =  mBluetoothDevice.connectGatt(context,false, mBleCallback); 
        				  mScanning = false;  
        				  scanLeDevice(false);    //   	  
        				}
                   }       	     
          	 }
      };   
      
      
      
      private  void TimeOutTimer(){
    	  
    	    if(timer==null) timer = new Timer();  
    	    
    	    if(task==null){
    	    	
    	    	 task = new TimerTask() {
					  
				 @Override  
				 public void run() {
				        	
				 if((CMDStatus!=0)|(CMDStatus!=1)){
							 mHandler.obtainMessage(1).sendToTarget(); //超时
					 }
						   
			     if (timer != null) {  timer.cancel(); timer=null; }
				 if (task  != null) {  task.cancel();  task=null;   }
				        	
				 }  
			   };   	 
				  
				   timer.schedule(task, 3000, 3000); //   
    	     }
    	  
    	  
    	  
      }
      
      
    /***
     * 校验接收到的数据是否正确 
     */
   private Boolean CheckSum(){
    	 int R = 0;		 
  	     for(int i=0;i<receive[2];i++){
  	    	  R = R + receive[3+i]&0xff;
  	      }			 
  			
  		   byte result=(byte)(256-R);	
  		   
    	   if(result==receive[receive.length-1])  //比较计算出来的check和传递过来的checksum是否相等
    	           return true;
		   else    return false;  	  
       }
  
       
        /**
         * 设置SN序列号
         * @param sn
         * @param listener
         */
		  public  void  SetDeviceSN(String sn, DataReceiveListener listener){
	    	  // this.DataListener = listener;
			  LISTENER.add(listener);
			   
			  DobotMessage  msg = new DobotMessage();
	    	  msg.id=0;
	    	  msg.rw=1;
	    	  msg.isQueued=0;
	    	  
	    	  byte[] ss= sn.getBytes();
		      msg.params = ss;
	    	  msg.paramsLen=ss.length;
	    	  CommandQueue0.add(msg.getCommand());//加入到即时命令队列中
		 }
		  
		  
		      /**
		     * 获取序列号
		     */
		   public  void  GetDeviceSN(DataReceiveListener listener){
		  	  
			  LISTENER.add(listener);
			  
		  	  DobotMessage  msg = new DobotMessage();
		  	  msg.id=0;
		  	  msg.rw=0;
		  	  msg.isQueued=0;
		  	  msg.params = new byte[0]; //params参数为空;
		  	  msg.paramsLen=0;
		  	  CommandQueue0.add(msg.getCommand());
		  	  
		    }
		   
		   
		   /**
		    * 解析出序列号值 以Strng返回
		    * @return
		    */
		   public  String  ReadDeviceSN(){
			  	  
			    if(receive==null){
			    	return  "";	
			    }
			    else{
			    	
			    	byte[]  dd =  new byte[receive[2]-2];
		            System.arraycopy(receive,5, dd, 0, receive[2]-2); 
	        	    String id = new String(dd);
	        	    return  id;	
			    }
				
			  }
			   
		   
		   /**
		     * OK
		     * 获取实时位姿
		     */
		    public  void   GetPose(DataReceiveListener listener){
		    
		      LISTENER.add(listener);//非队列消息放到LISTENER中
		  	  DobotMessage  msg = new DobotMessage();
		  	  msg.id=10;
		 	  msg.rw=0;
		 	  msg.isQueued=0;
		 	  msg.params = new byte[0]; //params参数为空
		      msg.paramsLen=0;
		      
		      CommandQueue0.add(msg.getCommand());
		    }
		    
		
		    public  TagPose   ReadPose(){
			     
                TagPose  pose = new TagPose();
	    	    
	    	    pose.setX(Util.byte2float(receive,5));
	    	    pose.setY(Util.byte2float(receive,9));
	    	    pose.setZ(Util.byte2float(receive,13));
	    	    pose.setR(Util.byte2float(receive,17));
				   
	    	    float[] jointAngle=new   float[4];
	    	    jointAngle[0]=Util.byte2float(receive,21);
	    	    jointAngle[1]=Util.byte2float(receive,25);
	    	    jointAngle[2]=Util.byte2float(receive,29);
	    	    jointAngle[3]=Util.byte2float(receive,33);
	    	    
	    	    pose.setJointAngle(jointAngle);
	    	   
	    	    return   pose;
		     }
			    
		    
			
		    /************************************************************************************/
		    /**************************************JOG功能**********************************************/
		    
		    /**
		     * OK
		     * @Function执行点动功能
		     * @param jogCmd
		     */
		      public  void  SetJOGCmd(JOGCmdParams jogCmd,DataReceiveListener listener){
			   
			  LISTENER1.add(listener);  //队列消息放到LISTENER1中
		 	  DobotMessage  msg = new DobotMessage();
		 	  msg.id=73;
		 	  msg.rw=1;
		 	  msg.isQueued=1;
		 	  
		 	  int isjoint=jogCmd.getIsJoint();
		 	  int cmd=jogCmd.getCmd();
		 	  byte[] CMD= {(byte) isjoint,(byte) cmd}; 
		 	  msg.params = CMD ;
		 	  msg.paramsLen=CMD.length;
		 	  
		 	  CommandQueue1.add(msg.getCommand());
		 	
		    }
		 	

		   /**
		    * OK
		    * @param jointParas
		    * @param isQueued
		    */
		   public  void   SetJOGJointParams(JOGJointParams  jointParas, Boolean isQueued, DataReceiveListener listener){
			   
			  if(isQueued==true)   LISTENER1.add(listener);  //队列命令放到LISTENER1中
			  else                  LISTENER.add(listener);  //即时命令消息放到LISTENER1中    
			  	 	  
		 	  DobotMessage  msg = new DobotMessage();
		 	  msg.id=70;
		 	  msg.rw=1;
		 	  
		 	  if(isQueued==true)      msg.isQueued=1;
		 	  else                    msg.isQueued=0;
		 	 
		 	  byte[]  CMD = new byte[32];
		 	  
		 	  byte[]  b0= new byte[4];
		 	  byte[]  b1= new byte[4];
		 	  byte[]  b2= new byte[4];
		 	  byte[]  b3= new byte[4];
		 	
		 	  byte[]  B0= new byte[4];
		 	  byte[]  B1= new byte[4];
		 	  byte[]  B2= new byte[4];
		 	  byte[]  B3= new byte[4];
		 	 
		 	  
		 	  b0=Util.float2byte(jointParas.getVelocity()[0]);
		 	  b1=Util.float2byte(jointParas.getVelocity()[1]);
		      b2=Util.float2byte(jointParas.getVelocity()[2]);
		 	  b3=Util.float2byte(jointParas.getVelocity()[3]);
		 	 
		 	  B0=Util.float2byte(jointParas.getAcceleration()[0]);
		 	  B1=Util.float2byte(jointParas.getAcceleration()[1]);
		      B2=Util.float2byte(jointParas.getAcceleration()[2]);
		 	  B3=Util.float2byte(jointParas.getAcceleration()[3]);
		 	 
		 	  
		 	  System.arraycopy(b0,0,CMD,0,4);   //插入第一个float的4个字节
		 	  System.arraycopy(b1,0,CMD,4,4);   
		 	  System.arraycopy(b2,0,CMD,8,4);   
		 	  System.arraycopy(b3,0,CMD,12,4);   
		 	  
		 	  System.arraycopy(B0,0,CMD,16,4);   
		 	  System.arraycopy(B1,0,CMD,20,4);   
		 	  System.arraycopy(B2,0,CMD,24,4);  
		 	  System.arraycopy(B3,0,CMD,28,4);  
		 	  	  
		 	  msg.params = CMD ;	 
		 	  msg.paramsLen=CMD.length;
		 	 	 	  
		 	  if(isQueued==true)     CommandQueue1.add(msg.getCommand());  
		 	  else                   CommandQueue0.add(msg.getCommand());  
		    }
		   
		   
		   /***************************************************************************************/
		   /*************************************队列指令******************************************************/
		   
		    
		  /**
		   * 获取指令队列剩余空间
		   */
		  public  void  GetQueuedCmdLeftSpace(DataReceiveListener listener){
			  LISTENER.add(listener);  //队列消息放到LISTENER1中
		      DobotMessage  msg = new DobotMessage();
		      msg.id = 247;
		      msg.paramsLen=0;	
		      msg.rw=0;
			  msg.isQueued=0;	
		      msg.params = new byte[0]; //params参数为空	
		    
		      CommandQueue0.add(msg.getCommand());
		    }
		    
		  
		  /**
		   * 解析出剩余的命令书
		   * @return
		   */
		  public  int  GetLeftSpace(){
			    
			    if(receive==null)  return 0;
			  
			    else
			     {
			    	int  value=   Util.bytesToint(receive,5); //从第5个字节开始的4个字节组成int
			        return  value;
			     }
			}
		   		  	  
		  /**
		   * 启动指令队列运行
		   */
		 public  void  SetQueuedCmdStartExec(DataReceiveListener listener){
			
			  LISTENER.add(listener);  //队列消息放到LISTENER1中
		      DobotMessage  msg = new DobotMessage();
		      msg.id = 240;
		      msg.rw=1;
			  msg.isQueued=0;	
              msg.paramsLen=0;	
		      msg.params = new byte[0]; //params参数为空	
		    
		      CommandQueue0.add(msg.getCommand()); 
		 } 
		  
		/**
		 *  停止指令队列运行
		 * @param listener
		 */
		 public  void   SetQueuedCmdStopExec(DataReceiveListener listener){
				
			  LISTENER.add(listener);  //队列消息放到LISTENER1中
		      DobotMessage  msg = new DobotMessage();
		      msg.id = 241;
		      msg.rw=1;
			  msg.isQueued=0;	
              msg.paramsLen=0;	
		      msg.params = new byte[0]; //params参数为空	
		    
		      CommandQueue0.add(msg.getCommand()); 
		 }   
		  
		  
		 
		 /**
		  * 强制停止指令队列运行
		  * @param listener
		  */
		 public  void SetQueuedCmdForceStopExec(DataReceiveListener listener){
				
			  LISTENER.add(listener);  //队列消息放到LISTENER1中
		      DobotMessage  msg = new DobotMessage();
		      msg.id = 242;
		      msg.rw=1;
			  msg.isQueued=0;	
              msg.paramsLen=0;	
		      msg.params = new byte[0]; //params参数为空	
		    
		      CommandQueue0.add(msg.getCommand()); 
		 }   
		 
		 /**
		  * 清空指令队列
		  * @param listener
		  */
		 public  void SetQueuedCmdClear(DataReceiveListener listener){
				
			  LISTENER.add(listener);  //队列消息放到LISTENER1中
		      DobotMessage  msg = new DobotMessage();
		      msg.id = 245;
		      msg.rw=1;
			  msg.isQueued=0;	
              msg.paramsLen=0;	
		      msg.params = new byte[0]; //params参数为空	
		    
		      CommandQueue0.add(msg.getCommand()); 
		 } 
		 
		 
		 /**
		  * 获取指令队列索引
		  * @param listener
		  */
		 public  void GetQueuedCmdCurrentIndex(DataReceiveListener listener){
				
			  LISTENER.add(listener);  //队列消息放到LISTENER1中
		      DobotMessage  msg = new DobotMessage();
		      msg.id = 246;
		      msg.rw=1;
			  msg.isQueued=0;	
              msg.paramsLen=0;	
		      msg.params = new byte[0]; //params参数为空	
		    
		      CommandQueue0.add(msg.getCommand()); 
		 } 
		 
		  
		  /*******************************************************************************************/
		  /******************************** EIO 功能 ***************************************************/
			 /**
			  * 设置 I/O 口复用
			  * @param plex
			  * @param isQueued
			  * @param listener
			  */
			public  void SetIOMultiplexing(IOMultiplexing  plex,Boolean isQueued,DataReceiveListener listener){
				
				  if(isQueued==true)   LISTENER1.add(listener);  //队列命令放到LISTENER1中
				  else                  LISTENER.add(listener);  //即时命令消息放到LISTENER1中    
				
				  DobotMessage  msg = new DobotMessage();
			 	  msg.id=130;
			 	  msg.rw=1;
			 	  msg.paramsLen=2;

			 	  if(isQueued==true)      msg.isQueued=1;
			 	  else                    msg.isQueued=0;
			 	  
			 	  msg.params = new byte[2]; //
			 	  msg.params[0] =(byte) plex.getAddress();
			 	  msg.params[1] =(byte) plex.getMultiplex();
			 	 
			 	 if(isQueued==true)     CommandQueue1.add(msg.getCommand());  
			 	 else                   CommandQueue0.add(msg.getCommand());  
				
			}
			
			
			/**
			 * 读取复用 I/O
			 * @param listener
			 */
			public void GetIOMultiplexing(DataReceiveListener listener){
				
				  LISTENER.add(listener);  
			      DobotMessage  msg = new DobotMessage();
			      msg.id =130;
			      msg.rw=0;
				  msg.isQueued=0;
				  
	              msg.paramsLen=0;	
			      msg.params = new byte[0]; //params参数为空	
			    
			      CommandQueue0.add(msg.getCommand()); 				
			  }
			 
			
			/**
			 * 设置 I/O 口输出电平
			 * @param address
			 * @param level
			 * @param isQueued
			 * @param listener
			 */
			public void SetIODO(int address,int  level,Boolean isQueued,DataReceiveListener listener){
				
				 if(isQueued==true)     LISTENER1.add(listener);  //队列命令放到LISTENER1中
				  else                  LISTENER.add(listener);  //即时命令消息放到LISTENER1中    
				
				  DobotMessage  msg = new DobotMessage();
			 	  msg.id=131;
			 	  msg.rw=1;
			 	  msg.paramsLen=2;

			 	  if(isQueued==true)      msg.isQueued=1;
			 	  else                    msg.isQueued=0;
			 	  
			 	 msg.params = new byte[2]; //
			 	 msg.params[0] =(byte)address;
			 	 msg.params[1] =(byte)level;
			 	 
			 	 if(isQueued==true)     CommandQueue1.add(msg.getCommand());  
			 	 else                   CommandQueue0.add(msg.getCommand());  
				
			}
			 
			/**
			 * 读取 I/O 输出电平
			 * @param listener
			 */
			public void GetIODO(DataReceiveListener listener){
				
			      LISTENER.add(listener);  //即时命令消息放到LISTENER1中    
				
				  DobotMessage  msg = new DobotMessage();
			 	  msg.id=131;
			 	  msg.rw=0;
			 	  msg.isQueued=0;
			 	  msg.paramsLen=0;
	              msg.params = new byte[0]; //
			 	 
			 	 CommandQueue0.add(msg.getCommand());  
			}
			
		  /*************************************************************************************************/
	     /**********************************PTP功能*********************************************************/
			
			/**
			 * 执行点位功能
			 * @param ptpcmd
			 * @param listener
			 */
			public void  SetPTPCmd(PTPCmd ptpcmd,DataReceiveListener listener){
				
			    LISTENER1.add(listener);  //即时命令消息放到LISTENER1中    
				
			      DobotMessage  msg = new DobotMessage();
			 	  msg.id=84;
			 	  msg.rw=1;
			 	  msg.isQueued=1;
			 	  
			 	  msg.paramsLen=17;
			 	  
			 	  byte[]  CMD = new byte[17];
			 	  
			 	  byte[]  b0 = new byte[1];
			 	  b0[0] = (byte) ptpcmd.getPtpMode();
			 	  
			 	  byte[]  b1 = new byte[4];
			 	  b1=Util.float2byte(ptpcmd.getX());
			 	  
			 	  byte[]  b2 = new byte[4];
			 	  b1=Util.float2byte(ptpcmd.getY());
			 	  
			 	  byte[]  b3 = new byte[4];
			 	  b1=Util.float2byte(ptpcmd.getZ());
			 	  
			 	  byte[]  b4 = new byte[4];
			 	  b1=Util.float2byte(ptpcmd.getR());
			 	  
			 	  System.arraycopy(b0,0,CMD,0,1); 
			 	  System.arraycopy(b1,0,CMD,1,4);   
			 	  System.arraycopy(b2,0,CMD,5,4);   
			 	  System.arraycopy(b3,0,CMD,9,4);   
			 	  System.arraycopy(b4,0,CMD,13,4);   
			 	  
	              msg.params = CMD; 
	              
	        	  CommandQueue1.add(msg.getCommand()); // 队列指令
			}
			
			/**
			 * 设置关节点位参数
			 * @param Params
			 * @param isQueued
			 * @param listener
			 */
		public  void  SetPTPJointParams(PTPJointParams  Params , Boolean isQueued, DataReceiveListener listener){
			
			  if(isQueued==true)     LISTENER1.add(listener);  //队列命令放到LISTENER1中
			  else                    LISTENER.add(listener);  //即时命令消息放到LISTENER1中    
			
			  DobotMessage  msg = new DobotMessage();
		 	  msg.id=80;
		 	  msg.rw=1;
		 	  msg.paramsLen=32;
		 	  if(isQueued==true)       msg.isQueued=1; //
			  else                    msg.isQueued=0;;//
		 	 
              byte[]  CMD = new byte[32];
		 	  
		 	  byte[]  b0= new byte[4];
		 	  byte[]  b1= new byte[4];
		 	  byte[]  b2= new byte[4];
		 	  byte[]  b3= new byte[4];
		 	
		 	  byte[]  B0= new byte[4];
		 	  byte[]  B1= new byte[4];
		 	  byte[]  B2= new byte[4];
		 	  byte[]  B3= new byte[4];
		 	 
		 	  
		 	  b0=Util.float2byte(Params.getVelocity()[0]);
		 	  b1=Util.float2byte(Params.getVelocity()[1]);
		      b2=Util.float2byte(Params.getVelocity()[2]);
		 	  b3=Util.float2byte(Params.getVelocity()[3]);
		 	 
		 	  B0=Util.float2byte(Params.getAcceleration()[0]);
		 	  B1=Util.float2byte(Params.getAcceleration()[1]);
		      B2=Util.float2byte(Params.getAcceleration()[2]);
		 	  B3=Util.float2byte(Params.getAcceleration()[3]);
		 	 
		 	  
		 	  System.arraycopy(b0,0,CMD,0,4);   //插入第一个float的4个字节
		 	  System.arraycopy(b1,0,CMD,4,4);   
		 	  System.arraycopy(b2,0,CMD,8,4);   
		 	  System.arraycopy(b3,0,CMD,12,4);   
		 	  
		 	  System.arraycopy(B0,0,CMD,16,4);   
		 	  System.arraycopy(B1,0,CMD,20,4);  
		 	  System.arraycopy(B2,0,CMD,24,4);  
		 	  System.arraycopy(B3,0,CMD,28,4);  
		 	  	  
		 	  msg.params = CMD ;
		 	  
			  if(isQueued==true)   CommandQueue1.add(msg.getCommand());  
		 	  else                 CommandQueue0.add(msg.getCommand());  
		  }
			
			/**
			 * 获取关节点位参数
			 * @param listener
			*/
			public  void GetPTPJointParams(DataReceiveListener listener){
				
				  LISTENER.add(listener);  //即时命令消息放到LISTENER1中    
				  DobotMessage  msg = new DobotMessage();
			  	  msg.id=80;
			 	  msg.rw=0;
			 	  msg.isQueued=0;
			 	  msg.params = new byte[0]; //params参数为空
			      msg.paramsLen=0;
			      
			      CommandQueue0.add(msg.getCommand());  
			   }
			
		  /**
		   * 获取指令队列剩余空间
		   */
		  public  byte[]  GetReturn(){
		    	 return  receive ;
		    }
		    
		  
		  public int GetCmdStatus(){
		    	
	          return   CMDStatus;	          
	    }
		  
		  
		  Handler  mHandler = new Handler() {  
			     
			public void handleMessage (Message msg) {//此方法在ui线程运行  
				   switch(msg.what) {
							
					      case 0:  // DataListener.OnReceive();  
					        	   byte[] bb= Util.getBooleanArray(receive[4]);
					        	   //判断当前的命令是即时命令还是队列命令
					        	   if(bb[6]==0)  { LISTENER.get(0).OnReceive(); //发送即时队列消息
					        	                   LISTENER.remove(0);          //发送完后 将发送该消息的listrner删除    用下一个listener发送下一条消息    达到发送者和接收者对应的关系
					        	                  
					        	   } 
					        	  
					        	  
					        	   else         { LISTENER1.get(0).OnReceive();  //队列消息
					        	                  LISTENER1.remove(0);           //发送完后 将发送该消息的listrner删除    用下一个listener发送下一条消息
					        	                 
					        	                 }
					               break;  //接收回调  
					               
					               
					      case 1:  CMDStatus=2; //超时	
					      
					               receive=null;
					               
					               BleIsIdle=true;//一次发送超时  进入空闲状态
					              
							       if(isQueuedTimeOut==false){  //及时命令超时
							    	   
							    	   Log.i("64", ""+"即时指令超时"+LISTENER.size()); 
							    	    
							    	//   LISTENER.get(0).OnReceive(); //发送即时队列消息
		        	                //   LISTENER.remove(0);  
		        	                
		        	                   
		        	                   if(LISTENER.size()==0){
		        	                	   
		        	                	   LISTENER1.get(0).OnReceive(); 
			        	                   LISTENER1.remove(0); 
		        	                	   
		        	                   }
		        	                   
		        	                   else{
		        	                	   
		        	                	   LISTENER.get(0).OnReceive(); 
			        	                   LISTENER.remove(0); 
		        	                   }
		        	                   
		        	                   
		        	                   
		        	                   
							        }
							    
							      else{                       //队列命令超时
							    	    Log.i("64", ""+"队列指令超时"+LISTENER.size()); 
							    	    LISTENER1.get(0).OnReceive(); //发送即时队列消息
		        	                    LISTENER1.remove(0); 
		        	                 
							        }
							    
				        	   
				               break;  
				               
				               
					      case 2:  mUiCallback.DobotConnected(mBluetoothGatt, mBluetoothDevice); 
					                
					               break;  
				                   
					      case 3:   CommandQueue0.clear();
					                CommandQueue0.clear();
					      
					                LISTENER.clear();
					                LISTENER.clear(); 
					    	  
					    	        mUiCallback.DobotDisconnected(mBluetoothGatt, mBluetoothDevice);   break;  
					    

		                  default: break;      
					      }   		
				      }  
				 };

}
