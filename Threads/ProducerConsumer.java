
import javax.xml.stream.events.StartDocument;

class SharedBuffer{
    private int data;
    private boolean available =false;

    public synchronized void produce(int value){
        while(available){
            try{
                wait();//buffer full, producer waits
            }
            catch(InterruptedExecution e){
                System.out.println(e);
            }
        }
        data=value;
        available=true;
        System.out.println("Produced: " + data);
        notify();//tell consumer to consume
    }

    public synchronized void consume(){
        while(!available){
            try{
                wait();//buffer empty waits
            }
            catch(InterruptedExecution e){
                System.out.println(e);
            }
        }
        System.out.println("COnsumed: "+ data);
        available=false;
        notify();//notify producer
    }
}

class Producer extends Thread{
    private SharedBuffer buffer;

    public Producer(SharedBuffer buffer){
        this.buffer=buffer;
    }

    public void run(){
        for(int i=0; i<=5; i++){
            buffer.produce(i);
            try {
                Thread.sleep(500);//sleep after producing
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class Consumer extends  Thread{
    private SharedBuffer buffer;

    public Consumer(SharedBuffer buffer){
        this.buffer=buffer;
    }

    public void run(){
        for(int i=1; i<=5; i++){
            buffer.consume();;
            try {
                Thread.sleep(800);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

}

public class ProducerConsumer {
    public static void main(String[] args) {
        SharedBuffer buffer=new SharedBuffer();

        Producer producer=new Producer(buffer);
        Consumer consumer=new Consumer(buffer);

        producer.start();
        consumer.start();
    }   
}
