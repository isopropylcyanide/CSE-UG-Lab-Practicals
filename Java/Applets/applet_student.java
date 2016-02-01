import  java.awt.*;
import java.applet.*;
import java.awt.event.*;

@SuppressWarnings("serial")

/*
<applet code="Applet Skeleton" width=300 height=600>
</applet>
*/

/*
Input: An applet that gets the details of maximum 50 students through a checkbox
Output: A textbox listing the input using as many threads as there are input.
*/

public class applet_student extends Applet implements Runnable,ActionListener{
    String message;
    Button make_threads;
    TextArea input,output;
    Thread []student_threads;

    public void init(){
        setForeground(Color.white);
        setBackground(Color.blue);

        input = new TextArea("",15,60,TextArea.SCROLLBARS_NONE);
        output = new TextArea("",15,60,TextArea.SCROLLBARS_NONE);

        setLayout(new FlowLayout());
        add(new Label("Enter Registration Details: "));

        make_threads = new Button("View threaded output-> ");
        add(input);
        add(make_threads); 
        add(output);

        make_threads.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae){

        String user_input[] = input.getText().split("\n");
        student_threads = new Thread[user_input.length];

        for(int i = 0; i<user_input.length; i++){
            student_threads[i] = new Thread(this,user_input[i]+" Thread ("+Integer.toString(i+1)+")");
            student_threads[i].start();
        }
    }

    public void run(){

        try{
            output.append(Thread.currentThread().getName()+"\n");
            Thread.sleep(100);
        }
        catch(InterruptedException e){
            System.out.println("Interrupted: "+e);
        }

    }
    public static void main(String[] args) {
    }
}
