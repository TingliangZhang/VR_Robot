package com.example.Dobot;

import java.util.ArrayList;

public class Util {
	
	
	 
	  public static float byte2float(byte[] b, int index) {    
		  
	      int l;                                             
	      l = b[index + 0];                                  
	      l &= 0xff;                                         
	      l |= ((long) b[index + 1] << 8);                   
	      l &= 0xffff;                                       
	      l |= ((long) b[index + 2] << 16);                  
	      l &= 0xffffff;                                     
	      l |= ((long) b[index + 3] << 24);                  
	    
	      return Float.intBitsToFloat(l);                    
	  }  
	  
	 
	  public static ArrayList<byte[]> SendPackage(byte[] sendBytes)
			{
				ArrayList<byte[]> list = new ArrayList<byte[]>();
				int BleSendByteLength = 20; 
				
				if(sendBytes.length <= BleSendByteLength)
				{ 
					list.add(sendBytes);
					return list;
				}
				
				int offset = 0;
				do
				{   
					int length = sendBytes.length - offset;
					byte[] resultByte = null;
					if(length >= BleSendByteLength)
					{
						resultByte = new byte[BleSendByteLength];
						System.arraycopy(sendBytes, offset, resultByte, 0, BleSendByteLength);
						offset += BleSendByteLength;
					}
					else
					{
						resultByte = new byte[length];
						System.arraycopy(sendBytes, offset, resultByte, 0, length);
						offset += length;
					} 
					list.add(resultByte); 
				}while(offset < sendBytes.length);
				return list;
			} 
			
			
	
			  
		    public static byte[] getBooleanArray(byte b) {  
		        byte[] array = new byte[8];  
		        for (int i = 7; i >= 0; i--) {  
		            array[i] = (byte)(b & 1);  
		            b = (byte) (b >> 1);  
		        }  
		        return array;  
		    }  

		    
		    
		    public static int  bytesToint(byte[] src, int  offset){
				
		    	int value;	
				value = (int) ((src[offset] & 0xFF) 
						  | ((src[offset+1] & 0xFF)<<8) 
						  | ((src[offset+2] & 0xFF)<<16) 
						  | ((src[offset+3] & 0xFF)<<24));
				return value;

		    	
		    } 
		    
		     
			public static byte[] float2byte(float f) {  
				  
				 int fbit = Float.floatToIntBits(f);  // 
			        
			      byte[] b = new byte[4];    
			      for (int i = 0; i < 4; i++) {    
			          b[i] = (byte) (fbit >> (24 - i * 8));    
			      }   
			      
			      int len = b.length;  
			      byte[] dest = new byte[len];  
			      System.arraycopy(b, 0, dest, 0, len);  
			      byte temp;  
			   
			      for (int i = 0; i < len / 2; ++i) {  
			    	  temp = dest[i];  
			          dest[i] = dest[len - i - 1];  
			          dest[len - i - 1] = temp;  
			      }  
			        
			       return dest;  
			  }  

}
