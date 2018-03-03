package CPlusDll;

import java.util.ArrayList;
import java.util.List;

import com.sun.jna.Callback;
import com.sun.jna.Library;  
import com.sun.jna.Native;
import com.sun.jna.Structure;
import com.sun.jna.ptr.IntByReference;

public interface DobotDll extends Library 
{  
	DobotDll instance = (DobotDll) Native.loadLibrary("DobotDll",  DobotDll.class);  
    
    public static class Pose extends Structure
    {
    	public static class ByReference extends Pose implements Structure.ByReference { }  
        public static class ByValue extends Pose implements Structure.ByValue{ } 
        
        public float x;
        public float y;
        public float z;
        public float r;
        public float[] jointAngle = new float[4];;

		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("x");  
		       a.add("y"); 
		       a.add("z"); 
		       a.add("r"); 
		       a.add("jointAngle");
		       return a;  
		}
    };
    
    public static class EndEffectorParams extends Structure
    {
        public float xBias;
        public float yBias;
        public float zBias;
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("xBias");  
		       a.add("yBias"); 
		       a.add("zBias"); 
		       return a;  
		}
    };
    
    public enum JOG
    {
        JogIdle,
        JogAPPressed,
        JogANPressed,
        JogBPPressed,
        JogBNPressed,
        JogCPPressed,
        JogCNPressed,
        JogDPPressed,
        JogDNPressed,
        JogEPPressed,
        JogENPressed
    };
    
    public static class JOGCmd extends Structure
    {
    	public JOGCmd() {
		    setAlignType(Structure.ALIGN_NONE);
		}
        public byte isJoint;
        public byte cmd;
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("isJoint");  
		       a.add("cmd"); 
		       return a;  
		}
    };
    
    public static class JOGJointParams extends Structure
    {
        public float[] velocity = new float[4];
        public float[] acceleration = new float[4];
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("velocity");  
		       a.add("acceleration"); 
		       return a;  
		}
    };
    
    public static class JOGCoordinateParams extends Structure
    {
        public float[] velocity = new float[4];
        public float[] acceleration = new float[4];
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("velocity");  
		       a.add("acceleration"); 
		       return a;  
		}
    };
    
    public static class JOGCommonParams extends Structure
    {
        public float velocityRatio;
        public float accelerationRatio;
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("velocityRatio");  
		       a.add("accelerationRatio"); 
		       return a;  
		}
    };
    
    public enum PTPMode {
        PTPJUMPXYZMode,
        PTPMOVJXYZMode,
        PTPMOVLXYZMode,

        PTPJUMPANGLEMode,
        PTPMOVJANGLEMode,
        PTPMOVLANGLEMode,

        PTPMOVJXYZINCMode,
        PTPMOVLXYZINCMode
    };
    
    public static class PTPCmd extends Structure
    {
    	public PTPCmd() {
		    setAlignType(Structure.ALIGN_NONE);
		}
    	
    	public static class ByReference extends PTPCmd implements Structure.ByReference { }  
        public static class ByValue extends PTPCmd implements Structure.ByValue{ }
        
        public byte ptpMode;
        public float x;
        public float y;
        public float z;
        public float r;
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("ptpMode");  
		       a.add("x"); 
		       a.add("y"); 
		       a.add("z"); 
		       a.add("r"); 
		       return a;  
		}
    };
    
    public static class PTPJointParams extends Structure
    {
        public float[] velocity = new float[4];
        public float[] acceleration = new float[4];
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("velocity");  
		       a.add("acceleration"); 
		       return a;  
		}
    };
    
    public static class PTPCoordinateParams extends Structure
    {
        public float xyzVelocity;
        public float rVelocity;
        public float xyzAcceleration;
        public float rAcceleration;
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("xyzVelocity");  
		       a.add("rVelocity"); 
		       a.add("xyzAcceleration");  
		       a.add("rAcceleration"); 
		       return a;  
		}
    };
    
    public static class PTPJumpParams extends Structure
    {
        public float jumpHeight;
        public float zLimit;
		@Override
		protected List<String> getFieldOrder() {
			List<String> a = new ArrayList<String>();  
		       a.add("jumpHeight");  
		       a.add("zLimit"); 
		       return a;  
		}
    };

    public enum DobotResult
    {
        DobotConnect_NoError,
        DobotConnect_NotFound,
        DobotConnect_Occupied
    };
    
    int ConnectDobot(char portName, int baudrate);
    void DisconnectDobot();
    void SetCmdTimeout(int cmdTimeout);
    int SetQueuedCmdClear();
    int SetQueuedCmdStartExec();
    int SetEndEffectorParams(EndEffectorParams endEffectorParams, boolean isQueued, IntByReference queuedCmdIndex);
    int DobotExec();

    // Pose
    int GetPose(Pose pose);

    // Jog functions
    int SetJOGCmd(JOGCmd jogCmd, boolean isQueued, IntByReference ueuedCmdIndex);
    int SetJOGJointParams(JOGJointParams jogJointParams, boolean isQueued, IntByReference ueuedCmdIndex);
    int SetJOGCoordinateParams(JOGCoordinateParams jogCoordinateParams, boolean isQueued, IntByReference ueuedCmdIndex);
    int SetJOGCommonParams(JOGCommonParams jogCommonParams, boolean isQueued, IntByReference ueuedCmdIndex);

    // Playback functions
    int SetPTPCmd(PTPCmd ptpCmd, boolean isQueued, IntByReference queuedCmdIndex);
    int SetPTPJointParams(PTPJointParams ptpJointParams, boolean isQueued, IntByReference ueuedCmdIndex);
    int SetPTPCoordinateParams(PTPCoordinateParams ptpCoordinateParams, boolean isQueued, IntByReference ueuedCmdIndex);
    int SetPTPJumpParams(PTPJumpParams ptpJumpParams, boolean isQueued, IntByReference ueuedCmdIndex);
}