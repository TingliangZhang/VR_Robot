package Dobot.Params;

public class TagPose {
	
	   private  float  x;
	   private  float  y;
	   private  float  z;
	   private  float  r;
	   
	   private  float[]   jointAngle=new float[4];

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


	public float[] getJointAngle() {
		return jointAngle;
	}


	public void setJointAngle(float[] jointAngle) {
		
		this.jointAngle = jointAngle;
	  }
	   
	  


}
