package Dobot.Params;

public class JOGCmdParams {
	
	public int isJoint; // 点动方式 0—坐标轴点动 1—关节点动
	 
    public int cmd;     //点动命令

    public int getIsJoint() {
		return isJoint;
	}

    public void setIsJoint(int isJoint) {
		this.isJoint = isJoint;
	}

    public int getCmd() {
		return cmd;
	}

    public void setCmd(int cmd) {
		this.cmd = cmd;
	}
     
}
