package com.example.Dobot;

import java.util.List;


import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;

public interface DobotCallbacks {
	


	//public void DobotFound(final BluetoothDevice device, int rssi, byte[] record);
	
	public void DobotConnected(final BluetoothGatt gatt,
				 				  final BluetoothDevice device);
	
	public void DobotDisconnected(final BluetoothGatt gatt,
			   						 final BluetoothDevice device);
	
	
	public void DobotConnectTimeOut();
	
	
	
	

	    public static class Null implements DobotCallbacks {//
		
		@Override
		public void DobotConnected(BluetoothGatt gatt, BluetoothDevice device) {}   
		
		@Override
		public void DobotDisconnected(BluetoothGatt gatt, BluetoothDevice device){}

		@Override
		public void DobotConnectTimeOut() {}  
	
	
   }	
	
}
