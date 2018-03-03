package Dobot.Params;

public class IOMultiplexing {



	public  int address;   //EIO Address（1~20）
	public  int multiplex; //EIO Function
	
	public int getAddress() {
		return address;
	}
	
	public void setAddress(int address) {
		this.address = address;
	}
	
	
	public int getMultiplex() {
		return multiplex;
	}
	public void setMultiplex(int multiplex) {
		this.multiplex = multiplex;
	}

	
	
}
