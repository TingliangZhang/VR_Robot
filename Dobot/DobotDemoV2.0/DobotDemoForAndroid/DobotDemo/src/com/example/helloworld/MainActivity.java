package com.example.helloworld;


import com.example.Dobot.DataReceiveListener;
import com.example.Dobot.Dobot;
import com.example.Dobot.DobotCallbacks;

import Dobot.Params.CmdState;
import Dobot.Params.JOGCmdParams;
import Dobot.Params.JogCmd;
import Dobot.Params.PTPCmd;
import Dobot.Params.PTPMode;
import Dobot.Params.TagPose;
import android.app.Activity;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements  DobotCallbacks{

	   Dobot  dobot ;	  
	   
	   private  Button X1,X2,Y1,Y2,Z1,Z2;
	   
	   private  Button Connect;
	   private  Button GetSN;
	   private  Button GetPose;
	   private  Button PTPCmd;
	   
	   private  Button StartQueue;	  
	   private  Button StopQueue;	  
	   private  Button ClearQueue;	  
	   
	   private  TextView  display;
	  
	   Boolean isConnect=false;
	    	  	  
	  @Override
	  protected void onCreate(Bundle savedInstanceState) {
		
		   super.onCreate(savedInstanceState);
		
		   setContentView(R.layout.activity_main1);
		   		   
		   dobot =new  Dobot(this,this);
		   
		   dobot.initialize();
		   	   
		   display=(TextView) findViewById(R.id.textView1);
		   
		   
		   Connect=(Button) findViewById(R.id.button1);
		   Connect.setOnClickListener(new OnClickListener() {			
				@Override
				public void onClick(View v) {
					
					if(isConnect==false){  
						 dobot.Connect();
					   }
					
					else{                     
						   dobot.close();
						   isConnect=false;
						   Connect.setText("Click to connect Dobot");
					   }
				  }
			});
	
		   
		   		   
		   GetSN= (Button) findViewById(R.id.button2);
		   GetSN.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				display.setText("");
				dobot.GetDeviceSN(new DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub
					    int ReturnCode  = dobot.GetCmdStatus(); 
					    
					    switch(ReturnCode){
					    
					          case  CmdState.Error  : 	 Toast.makeText(MainActivity.this, "return error" ,Toast.LENGTH_SHORT).show();   
					                                     break; 
					          
					          case  CmdState.Normal :    String sn = dobot.ReadDeviceSN();
					        	                         display.setText(sn);
					        	                         break; 
					        	                         
					          case  CmdState.TimeOut:    Toast.makeText(MainActivity.this, "return timeout" ,Toast.LENGTH_SHORT).show(); 
					                                     break; 
					          default:         break;
					    }
					    
					}
				});
				
			}
		});
		   
		   
		   GetPose= (Button) findViewById(R.id.button9);
		   GetPose.setOnClickListener(new OnClickListener() {
			   
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				display.setText("");
				dobot.GetPose(new DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub
					    int ReturnCode  = dobot.GetCmdStatus(); 
					    
					    switch(ReturnCode){
					    
					          case  CmdState.Error  : 	 Toast.makeText(MainActivity.this, "return error" ,Toast.LENGTH_SHORT).show();   
					                                     break; 
					          
					          case  CmdState.Normal :    TagPose  pose = dobot.ReadPose();
						                                 float x= pose.getX();
						                                 float y= pose.getY();
						                                 float z= pose.getZ();
						                                 float r= pose.getR();  
					        	                         display.setText(x+"  "+y+"  "+z+"  "+r);
					        	                         break; 
					        	                         
					          case  CmdState.TimeOut:    Toast.makeText(MainActivity.this, "return timeout" ,Toast.LENGTH_SHORT).show(); 
					                                     break; 
					          default:         break;
					    }
					    
					}
				});
				
			}
		});
		   
		   
		   PTPCmd= (Button) findViewById(R.id.button10);
		   PTPCmd.setOnClickListener(new OnClickListener() {
			   
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				PTPCmd ptp=new PTPCmd();
				ptp.setPtpMode(PTPMode.MOVL_ANGLE);					
				ptp.setX(45f);
				ptp.setY(45f);
				ptp.setZ(45f);
				ptp.setR(0);
				
				dobot.SetPTPCmd(ptp, new  DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub
						  int ReturnCode  = dobot.GetCmdStatus(); 
						    
						    switch(ReturnCode){
						    
						          case  CmdState.Error  : 	 Toast.makeText(MainActivity.this, "return error" ,Toast.LENGTH_SHORT).show();   
						                                     break; 
						          
						          case  CmdState.Normal :    byte[] value = dobot.GetReturn();
						        	                         break; 
						        	                         
						          case  CmdState.TimeOut:    Toast.makeText(MainActivity.this, "return timeout" ,Toast.LENGTH_SHORT).show(); 
						                                     break; 
						          default:         break;
						       }
					        }
				      });
			       }
		      });
		   
		   
		   StartQueue= (Button) findViewById(R.id.button11);
		   StartQueue.setOnClickListener(new OnClickListener() {
			   
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				dobot.SetQueuedCmdStartExec(new  DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub

						// TODO Auto-generated method stub
						  int ReturnCode  = dobot.GetCmdStatus(); 
						    
						    switch(ReturnCode){
						    
						          case  CmdState.Error  : 	 Toast.makeText(MainActivity.this, "return error" ,Toast.LENGTH_SHORT).show();   
						                                     break; 
						          
						          case  CmdState.Normal :    break; 
						        	                         
						          case  CmdState.TimeOut:    Toast.makeText(MainActivity.this, "return timeout" ,Toast.LENGTH_SHORT).show(); 
						                                     break; 
						          default:         break;
						    }					  
					  }
				});				
			}
		});
		   
		   
		   StopQueue= (Button) findViewById(R.id.button12);
		   StopQueue.setOnClickListener(new OnClickListener() {
			   
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				dobot.SetQueuedCmdForceStopExec(new  DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub

						// TODO Auto-generated method stub
						  int ReturnCode  = dobot.GetCmdStatus(); 
						    
						    switch(ReturnCode){
						    
						          case  CmdState.Error  : 	 Toast.makeText(MainActivity.this, "return error" ,Toast.LENGTH_SHORT).show();   
						                                     break; 
						          
						          case  CmdState.Normal :    break; 
						        	                         
						          case  CmdState.TimeOut:    Toast.makeText(MainActivity.this, "return timeout" ,Toast.LENGTH_SHORT).show(); 
						                                     break;
						          default:         break;
						    }					  
					  }
				});				
			}
		});
		   
		   
		   ClearQueue= (Button) findViewById(R.id.button13);
		   ClearQueue.setOnClickListener(new OnClickListener() {
			   
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				dobot.SetQueuedCmdClear(new  DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub

						// TODO Auto-generated method stub
						  int ReturnCode  = dobot.GetCmdStatus(); 
						    
						    switch(ReturnCode){
						    
						          case  CmdState.Error  : 	 Toast.makeText(MainActivity.this, "return error" ,Toast.LENGTH_SHORT).show();   
						                                     break; 
						          
						          case  CmdState.Normal :    break; 
						        	                         
						          case  CmdState.TimeOut:    Toast.makeText(MainActivity.this, "return timeout" ,Toast.LENGTH_SHORT).show(); 
						                                     break; 
						          default:         break;
						    }					  
					  }
				});				
			}
		});
		   
		   
		   
		   TouchListener listener = new TouchListener();
		   
		   X1=(Button) findViewById(R.id.button3);  //X+
		   X1.setOnTouchListener(listener);
		   
		   X2=(Button) findViewById(R.id.button5);  //X-
		   X2.setOnTouchListener(listener);
		   
		   Y1=(Button) findViewById(R.id.button4);  //Y+
		   Y1.setOnTouchListener(listener);
		   
		   Y2=(Button) findViewById(R.id.button6);  //Y-
		   Y2.setOnTouchListener(listener);
		   
		   
		   Z1=(Button) findViewById(R.id.button7); //Z+
		   Z1.setOnTouchListener(listener);
		   
		   Z2=(Button) findViewById(R.id.button8);//Z-
		   Z2.setOnTouchListener(listener);
		   
	  }

	  
	   class TouchListener implements OnTouchListener{  
		   
	  
	        public boolean onTouch(View v, MotionEvent event) {  
	        	
	        	switch(v.getId()){
	        	
	        	case   R.id.button3:        //x+
	        		   if(event.getAction() == MotionEvent.ACTION_DOWN){  
		                   
		               JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.AN_DOWN);       						   
					   dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});
						}  
		                
	        		   if(event.getAction() == MotionEvent.ACTION_UP){
		        			
		        		JOGCmdParams  JogcmdParams = new JOGCmdParams();
						JogcmdParams.setIsJoint(JogCmd.JOINT);  
						JogcmdParams.setCmd(JogCmd.IDEL);       						   
						dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});					  	        				        			
		                }   
		        				               
	        		    break;
	        	
	        	case   R.id.button5:  //x-
	        		   if(event.getAction() == MotionEvent.ACTION_DOWN){  
		                   
		               JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.AP_DOWN);       						   
					   dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});
						}  
		                
	        		   if(event.getAction() == MotionEvent.ACTION_UP){
		        			
		        			JOGCmdParams  JogcmdParams = new JOGCmdParams();
							JogcmdParams.setIsJoint(JogCmd.JOINT);  
							JogcmdParams.setCmd(JogCmd.IDEL);       						   
							dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});					  	        				        			
		                }   
		        				               
	        		    break;
	        		    
	        		    
	        	case   R.id.button4:  //Y+
	        		   if(event.getAction() == MotionEvent.ACTION_DOWN){  
		                   
		               JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.BP_DOWN);       						   
					   dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});
						}  
		                
	        		   if(event.getAction() == MotionEvent.ACTION_UP){
		        			
		        	  JOGCmdParams  JogcmdParams = new JOGCmdParams();
					  JogcmdParams.setIsJoint(JogCmd.JOINT);  
					  JogcmdParams.setCmd(JogCmd.IDEL);       						   
					  dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});					  	        				        			
		                }   
		        				               
	        		    break;
	        		    
	        	case   R.id.button6:  //Y-
	        		   if(event.getAction() == MotionEvent.ACTION_DOWN){  
		                   
		               JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.BN_DOWN);       						   
					   dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});
						}  
		                
	        		   if(event.getAction() == MotionEvent.ACTION_UP){
		        			
		        	   JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.IDEL);       						   
							 dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});					  	        				        			
		                }   
		        				               
	        		    break;
	        		    
	        	case   R.id.button7:  //Z+
	        		   if(event.getAction() == MotionEvent.ACTION_DOWN){  
		                   
		               JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.CN_DOWN);       						   
					   dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});
						}  
		                
	        		   if(event.getAction() == MotionEvent.ACTION_UP){
		        			
		        		JOGCmdParams  JogcmdParams = new JOGCmdParams();
						JogcmdParams.setIsJoint(JogCmd.JOINT);  
						JogcmdParams.setCmd(JogCmd.IDEL);       						   
						dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});					  	        				        			
		                }   
		        				               
	        		    break;    
	        		    
	        	case   R.id.button8:  //Z-
	        		   if(event.getAction() == MotionEvent.ACTION_DOWN){  
		                   
		               JOGCmdParams  JogcmdParams = new JOGCmdParams();
					   JogcmdParams.setIsJoint(JogCmd.JOINT);  
					   JogcmdParams.setCmd(JogCmd.CP_DOWN);       						   
					   dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});
						}  
		                
	        		   if(event.getAction() == MotionEvent.ACTION_UP){
		        			
		        			JOGCmdParams  JogcmdParams = new JOGCmdParams();
							JogcmdParams.setIsJoint(JogCmd.JOINT);  
							JogcmdParams.setCmd(JogCmd.IDEL);       						   
							 dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
								
								@Override
								public void OnReceive() {
									// TODO Auto-generated method stub
								 }
							});					  	        				        			
		                  }   
		        		 break;
	        		
	        	   default:       break;
	        	}
	        	
	            return false;  
	        }  
	   }  
	  
	  
	@Override
	public void DobotConnectTimeOut() {
		// TODO Auto-generated method stub
		Toast.makeText(MainActivity.this , "timeout", Toast.LENGTH_SHORT).show();
	}

	@Override
	public void DobotConnected(BluetoothGatt arg0, BluetoothDevice arg1) {
		// TODO Auto-generated method stub
		Toast.makeText(MainActivity.this , "Connected", Toast.LENGTH_SHORT).show();
		Connect.setText("Click to  disconnect Dobot"); 
		isConnect=true;
	}

	@Override
	public void DobotDisconnected(BluetoothGatt arg0, BluetoothDevice arg1) {
		// TODO Auto-generated method stub
		Toast.makeText(MainActivity.this , "Disconnected", Toast.LENGTH_SHORT).show();
		Connect.setText("Click to connect Dobot");  
		isConnect=false;
	}
	
}







