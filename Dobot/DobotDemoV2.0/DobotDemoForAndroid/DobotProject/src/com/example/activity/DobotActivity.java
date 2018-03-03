package com.example.activity;

import com.example.Dobot.DataReceiveListener;
import com.example.Dobot.Dobot;
import com.example.Dobot.DobotCallbacks;

import Dobot.Params.JOGCmdParams;
import Dobot.Params.JOGJointParams;
import Dobot.Params.JogCmd;
import Dobot.Params.TagPose;
import Dobot.demo.R;
import android.app.Activity;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class DobotActivity extends Activity  implements DobotCallbacks {

	Button connect;
	
	Button Send;
	
	Button Send1;
	
	Button Send2;
	
	Button S4,S5;
	
	Boolean isConnect=false;
	
	Dobot  dobot ;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.dobot_activity);
		
		dobot =new  Dobot(this,this);
	
		dobot.initialize();
		
		connect =(Button) findViewById(R.id.button1);
	    connect.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
			
				if(isConnect==false){     //已断开状态
					 dobot.Connect();
				  }
				else{                     //已连接状态
					 dobot.close();
					 isConnect=false;
					 connect.setText("click to connect");
				  }
				
			}
		});
	    
	    
	    S4 =(Button) findViewById(R.id.button5);
	    S4.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				
				JOGCmdParams  JogcmdParams = new JOGCmdParams();
				JogcmdParams.setIsJoint(JogCmd.JOINT);  
				JogcmdParams.setCmd(JogCmd.CP_DOWN);       
			
				dobot.SetJOGCmd(JogcmdParams, new DataReceiveListener() {
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub
						   Toast.makeText(DobotActivity.this , "----回调S4---"+"state "+dobot.GetCmdStatus(), Toast.LENGTH_SHORT).show();
					    }
			      });
			   }
		  });
	    
	    
	    S5 =(Button) findViewById(R.id.button6);
	    
	    S5.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				
				JOGCmdParams  JogcmdParams = new JOGCmdParams();
				JogcmdParams.setIsJoint(JogCmd.JOINT);  
				JogcmdParams.setCmd(JogCmd.CN_DOWN);       
			
				dobot.SetJOGCmd(JogcmdParams,new  DataReceiveListener() {
					
					@Override
					public void OnReceive() {
						// TODO Auto-generated method stub
						Toast.makeText(DobotActivity.this , "----回调S5---"+"state "+dobot.GetCmdStatus(), Toast.LENGTH_SHORT).show();
					
						dobot.GetReturn();
					  }
				});
			}
		 });
	    
	    
	    Send1 =(Button) findViewById(R.id.button3);
	    Send1.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				
	     dobot.GetDeviceSN(new DataReceiveListener() {
					
					@Override
					public void OnReceive(){
						// TODO Auto-generated method stub
						 
				           String ss=dobot.ReadDeviceSN();
					    
		        		   Toast.makeText(DobotActivity.this , "----回调S2---"+ss+ "   返回值--"+"状态值 "+dobot.GetCmdStatus(), Toast.LENGTH_SHORT).show();
					    }
				});  			    
			}
		});
	    
	    
	    Send2 =(Button) findViewById(R.id.button4);
	    Send2.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				
	    dobot.GetPose(new DataReceiveListener() {
					
					@Override
					public void OnReceive(){
						// TODO Auto-generated method stub
				         TagPose  pose = dobot.ReadPose();
				         float x= pose.getX();
				         float y= pose.getY();
				         float z= pose.getZ();
				         float r= pose.getR();      
				         
					    Toast.makeText(DobotActivity.this , "---回调S3---POSE:-"+x+"  "+y+"  "+z+"  "+r, Toast.LENGTH_SHORT).show();
					  }
				 });  			    
			  }
		 });
	    
	    	   
	    Send =(Button) findViewById(R.id.button2);
	    Send.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				
				/*
				 * dobot.SetDeviceSN("A",new DataReceiveListener() {
					
					@Override
					public void OnReceive(){
						// TODO Auto-generated method stub
						Toast.makeText(DobotActivity.this , "----回调S1---", Toast.LENGTH_SHORT).show();
					  }
				  }); 
				  
				 */	
				
				
				 /*   dobot.GetQueuedCmdLeftSpace(new  DataReceiveListener() {
					
					  @Override
					  public void OnReceive() {
						// TODO Auto-generated method stub
						   int len = dobot.GetLeftSpace();
						   Toast.makeText(DobotActivity.this , "---回调S1--leftspace---"+len, Toast.LENGTH_SHORT).show();
					     }
				   });
				   */
				    
				    
				    JOGJointParams  par = new JOGJointParams();			  
					par.setVelocity_x(20.0f);
					par.setVelocity_y(20.0f);
					par.setVelocity_z(20.0f);
					par.setVelocity_r(20.0f);
					
					par.setAcceleration_x(.0f);
					par.setAcceleration_y(1.0f);
					par.setAcceleration_z(1.0f);
					par.setAcceleration_r(1.0f);
					     
					dobot.SetJOGJointParams(par, false, new DataReceiveListener() {
					
					@Override
					public void OnReceive(){
						   Toast.makeText(DobotActivity.this , "---回调S1---", Toast.LENGTH_SHORT).show();
					   }
			    	});   
			   }
		  });
		
	}
	
	
	@Override
	public void DobotConnected(BluetoothGatt gatt, BluetoothDevice device) {
		// TODO Auto-generated method stub
		   Toast.makeText(DobotActivity.this , "----Connected---", Toast.LENGTH_SHORT).show();
		   connect.setText("click to  Disconnect"); 
		   isConnect=true;
	}
	
	@Override
	public void DobotDisconnected(BluetoothGatt gatt, BluetoothDevice device) {
		// TODO Auto-generated method stub
		   Toast.makeText(DobotActivity.this , "----Disconnected---", Toast.LENGTH_SHORT).show();
		   connect.setText("click  to  connect"); 
		   isConnect=false;
	}

	
	@Override
	public void DobotConnectTimeOut() {
		// TODO Auto-generated method stub
		   Toast.makeText(DobotActivity.this , "--Time out--", Toast.LENGTH_SHORT).show();
	}
	



}