package mvc;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.lang.Math;

public class mouselistener implements MouseMotionListener,MouseListener{
	
	 
	Sphere sphere;
    static double y=0;
	
	public mouselistener(Sphere sphere) {
		super();
		this.sphere = sphere;
	}

	@Override
      public void mouseClicked(MouseEvent e) {
	    // TODO Auto-generated method stub
	  }

	  @Override
	  public void mousePressed(MouseEvent e) {       //获取点击鼠标时坐标点的位置
	    // TODO Auto-generated method stub
	   y=e.getX();
	   System.out.println(y);
	  }

	  @Override
	  public void mouseReleased(MouseEvent e) {
	    // TODO Auto-generated method stub
	   // System.out.println("鼠标松开");
	  }

	  @Override
	  public void mouseEntered(MouseEvent e) {
	   
	  }

	  @Override
	  public void mouseExited(MouseEvent e) {
	    // TODO Auto-generated method stub
	   //System.out.println("鼠标已经移出窗体");
	  }

	  @Override
	  public void mouseDragged(MouseEvent e) {          //获取鼠标拖动时坐标点的位置
	    // TODO Auto-generated method stub
	   double x=e.getX();
	   x=Math.abs(x-y)/2;                              //根据鼠标按下时的初始点位置和鼠标拖动时的点的位置，计算二者之间的距离，距离的1/2，即所求的半径值
	   sphere.setRadius(x);
	   
	  }

	  @Override
	  public void mouseMoved(MouseEvent e) {
	    // TODO Auto-generated method stub
	  }


}
