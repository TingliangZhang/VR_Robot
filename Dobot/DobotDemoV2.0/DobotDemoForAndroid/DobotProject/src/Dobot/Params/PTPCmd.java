package Dobot.Params;

public class PTPCmd {
	
	public   int  ptpMode;
	
	public float x; //x,y,z,r 为 ptpMode 运动方式的参数，可为坐标、
	            //关节角度、或者坐标/角度增量
	public float y;
	
	public float z;
	
	public float r;

	public int getPtpMode() {
		return ptpMode;
	}

	public void setPtpMode(int ptpMode) {
		this.ptpMode = ptpMode;
	}

	public float getX() {
		return x;
	}

	public void setX(float x) {
		this.x = x;
	}

	public float getY() {
		return y;
	}

	public void setY(float y) {
		this.y = y;
	}

	public float getZ() {
		return z;
	}

	public void setZ(float z) {
		this.z = z;
	}

	public float getR() {
		return r;
	}

	public void setR(float r) {
		this.r = r;
	}
	
}
