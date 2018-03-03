package Dobot.Params;

public class JOGJointParams {
	
	 public float[] velocity = new float[4];      
     public float[] acceleration = new float[4];  
     
     //四轴关节速度
     public float velocity_x;
     public float velocity_y;
     public float velocity_z;
     public float velocity_r;
	
     //四轴关节加速度
     public float acceleration_x ;
     public float acceleration_y ;
     public float acceleration_z ;
     public float acceleration_r ;
     
     
     public float[] getVelocity() {
    	 
    	 velocity[0]=velocity_x;
    	 velocity[1]=velocity_y;
    	 velocity[2]=velocity_z;
    	 velocity[3]=velocity_r;
    	 
    	 return  velocity;
 	}
      
     
   public float[] getAcceleration() {
    	 
	   acceleration[0]=acceleration_x;
	   acceleration[1]=acceleration_y;
	   acceleration[2]=acceleration_z;
	   acceleration[3]=acceleration_r;
    	 
       return  velocity;
 	}
      
     
        
     public float getVelocity_x() {
		return velocity_x;
	}
     
     
     public void setVelocity_x(float velocity_x) {
		this.velocity_x = velocity_x;
	}
     
     
     
     public float getVelocity_y() {
		return velocity_y;
	}
     
     
     public void setVelocity_y(float velocity_y) {
		this.velocity_y = velocity_y;
	}
     
     
     public float getVelocity_z() {
		return velocity_z;
	}
     
     
     public void setVelocity_z(float velocity_z) {
		this.velocity_z = velocity_z;
	}
     
     
     public float getVelocity_r() {
		return velocity_r;
	}
     
     
     public void setVelocity_r(float velocity_r) {
		this.velocity_r = velocity_r;
	}
     
     
     public float getAcceleration_x() {
		return acceleration_x;
	}
     
     
     public void setAcceleration_x(float acceleration_x) {
		this.acceleration_x = acceleration_x;
	}
     
     
     public float getAcceleration_y() {
		return acceleration_y;
	}
     
     
     public void setAcceleration_y(float acceleration_y) {
		this.acceleration_y = acceleration_y;
	}
     
     
     public float getAcceleration_z() {
		return acceleration_z;
	}
     
     
	public void setAcceleration_z(float acceleration_z) {
		this.acceleration_z = acceleration_z;
	}
	public float getAcceleration_r() {
		return acceleration_r;
	}
	
	
	public void setAcceleration_r(float acceleration_r) {
		this.acceleration_r = acceleration_r;
	}
     
     
}
