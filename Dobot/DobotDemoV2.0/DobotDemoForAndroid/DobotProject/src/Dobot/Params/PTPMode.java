package Dobot.Params;

public class PTPMode {
	
	public  static  int   JUMP_XYZ=0; //门型运动，参数为目标点坐标; 
	
	public  static  int   MOVJ_XYZ=1;//门型运动，参数为目标点坐标; 
	
	public  static  int   MOVL_XYZ=2;//直线运动，参数为目标点坐标
	
	public  static  int   JUMP_ANGLE=3 ;//门型运动，参数为目标点关节角度
	
	public  static  int   MOVJ_ANGLE=4; //关节运动，参数为目标点关节角度
	
	public  static  int   MOVL_ANGLE=5;//直线运动，参数为目标点关节角度
	
	public  static  int   MOVJ_INC=6; //关节运动增量模式，参数为目标点关节角度增量
	
	public  static  int   MOVL_INC=7; //直线运动增量模式，参数为目标点坐标增量
	
	public  static  int   MOVJ_XYZ_INC=8;//关节运动增量模式，参数为目标点坐标增量
	
	public  static  int   JUMP_MOVL_XYZ=9; //门型运动，平移时运动模式为 MOVL
	
	

}
