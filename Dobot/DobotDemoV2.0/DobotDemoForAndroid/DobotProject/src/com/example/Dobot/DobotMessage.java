package com.example.Dobot;

import android.util.Log;

public class DobotMessage {
	
	public  byte[]   cmd;
	public  int      id;
	
	public  int      rw;
	public  int      isQueued;
	
	public  int      paramsLen;
	public  byte[]   params;
	
	
	
	byte[] Head={(byte) 0xaa,(byte) 0xaa};
	byte[] Len = new  byte[1];
	byte[] ID  = new  byte[1];
	byte[] Ctrl= new  byte[1];
	
	byte[] Params=params;	
	byte[] CheckSum=new byte[1];
	
	
	
	public  byte[] getCommand(){
		
		
		 Len[0] = (byte) (paramsLen+2);
		 ID[0]  = (byte) id;
		
		 if(rw==0){
			    if(isQueued==0)  
			    	 Ctrl[0]=0;
			     else           
			    	 Ctrl[0]=2; 
			     }
		 else{
			     if(isQueued==0) 
			    	   Ctrl[0]=1;
			     else          
			    	   Ctrl[0]=3; 
			 }
		 
		 Params = params;  //  Params
		 
		 int R = 0;		 
	     for(int i=0;i<Params.length;i++){
	    	  R = R + Params[i]&0xff;
	      }			 
				 
	     CheckSum[0] =	(byte)(256-(ID[0] + Ctrl[0] + R));	 
	   
	     cmd = new byte[6+paramsLen];                     
		
		 System.arraycopy(Head,0,cmd, 0, 2);              
		 System.arraycopy(Len,0,cmd, 2, 1);               
		 System.arraycopy(ID,0,cmd,3,1);                
         System.arraycopy(Ctrl,0,cmd,4,1);                 
         System.arraycopy(Params,0,cmd,5,Params.length);  
         System.arraycopy(CheckSum,0,cmd,Params.length+5,1); 
        
         return cmd;		
	 }
	
}
