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
	  public void mousePressed(MouseEvent e) {       //��ȡ������ʱ������λ��
	    // TODO Auto-generated method stub
	   y=e.getX();
	   System.out.println(y);
	  }

	  @Override
	  public void mouseReleased(MouseEvent e) {
	    // TODO Auto-generated method stub
	   // System.out.println("����ɿ�");
	  }

	  @Override
	  public void mouseEntered(MouseEvent e) {
	   
	  }

	  @Override
	  public void mouseExited(MouseEvent e) {
	    // TODO Auto-generated method stub
	   //System.out.println("����Ѿ��Ƴ�����");
	  }

	  @Override
	  public void mouseDragged(MouseEvent e) {          //��ȡ����϶�ʱ������λ��
	    // TODO Auto-generated method stub
	   double x=e.getX();
	   x=Math.abs(x-y)/2;                              //������갴��ʱ�ĳ�ʼ��λ�ú�����϶�ʱ�ĵ��λ�ã��������֮��ľ��룬�����1/2��������İ뾶ֵ
	   sphere.setRadius(x);
	   
	  }

	  @Override
	  public void mouseMoved(MouseEvent e) {
	    // TODO Auto-generated method stub
	  }


}
