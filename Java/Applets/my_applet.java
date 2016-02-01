import  java.awt.*;
import java.applet.*;
import java.awt.event.*;

@SuppressWarnings("serial")

/*
<applet code="Applet Skeleton" width=300 height=600>
</applet>
*/

public class my_applet extends Applet implements Runnable,ActionListener,MouseListener{
    String message;
    Button sum;
    TextField x1,y1,mouseState;
    TextArea ans;

    public void init(){
        setForeground(Color.white);
        setBackground(Color.blue);
        message = "Inside Applet";

        x1 = new TextField(10);
        y1 = new TextField(10);
        mouseState = new TextField(30);
        ans = new TextArea();

        setLayout(new FlowLayout());
        add(new Label("Enter x: ")); add(x1);
        add(new Label("Enter y: ")); add(y1);

        sum = new Button("Click to sum-> ");
        add(sum); add(ans);
        add(mouseState);

        addMouseListener(this);
        sum.addActionListener(this);
        addMouseMotionListener(new MouseMotionAdapter() {

            public void mouseMoved(MouseEvent me){
                mouseState.setText("Mouse Currently at: "+ "(" +me.getX()+","+me.getY()+") ");
            }

        });
    }

    public void actionPerformed(ActionEvent e){

        int x = Integer.parseInt(x1.getText());
        int y = Integer.parseInt(y1.getText());
        ans.append(" The required sum is: "+ Integer.toString(x+y));
    }


    public void mouseClicked(MouseEvent me){
        mouseState.setText("Mouse Clicked at: "+ "(" +me.getX()+","+me.getY()+") ");
    }

    public void mouseEntered(MouseEvent me){
        mouseState.setText("Mouse Entered at: "+ "(" +me.getX()+","+me.getY()+") ");
    }

    public void mouseExited(MouseEvent me){
        mouseState.setText("Mouse Exited. Last seen at: "+ "(" +me.getX()+","+me.getY()+") ");
    }

    public void mousePressed(MouseEvent me){
        mouseState.setText("Mouse Pressed at: "+ "(" +me.getX()+","+me.getY()+") ");
    }

    public void mouseReleased(MouseEvent me){
        mouseState.setText("Mouse Released at: "+ "(" +me.getX()+","+me.getY()+") ");
    }

    public void run(){

    }
    public static void main(String[] args) {
            // new my_applet();
    }
}
