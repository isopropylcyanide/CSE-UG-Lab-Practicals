
class Threads extends Thread{

    Threads(ThreadGroup g, String s){
        super(g,s);
    }
    public void run(){
        for(int i=0; i<2; i++){
            System.out.println(Thread.currentThread());
            Thread.State ts = getState();
            System.out.println(ts);
        }
    }

    public static void main(String[] args) {
        ThreadGroup grp = new ThreadGroup("Group 1");
        Thread t2 = new Threads(grp,"Thread 2");

        try{
            t2.start();
            t2.join();
        }
        catch (Exception e){}

        for(int i=0; i<2; i++)
            System.out.println(Thread.currentThread());
    }

}