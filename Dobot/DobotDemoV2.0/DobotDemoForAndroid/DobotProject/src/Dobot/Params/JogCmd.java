package Dobot.Params;

public class JogCmd {
	
	public  static  int	 AXIS=0; // 坐标轴点动 
	public  static  int	 JOINT=1;// 关节点动
	
	/**
	 * 点动命令详细说明
	 */
	public  static  int  IDEL=0; //
	
	public  static  int	 AP_DOWN=1; // X+/Joint1+
	public  static  int	 AN_DOWN=2;// X-/Joint1-
	
	public  static  int	 BP_DOWN=3; // Y+/Joint2+
	public  static  int	 BN_DOWN=4; // Y-/Joint2-
	
	public  static  int	 CP_DOWN=5;// Z+/Joint3+
	public  static  int	 CN_DOWN=6; // Z-/Joint3-
	
	public  static  int	 DP_DOWN=7;// R+/Joint4+
	public  static  int	 DN_DOWN=8;// R-/Joint4-	
	
}
