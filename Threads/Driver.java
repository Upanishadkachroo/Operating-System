package Threads;

class Sum {
    private int sum;// Shared resource between threads

    public int getSum() {
        return sum;
    }

    public void setSum(int sum) {
        this.sum = sum;
    }
}

class Summation implements Runnable {
    private int upper;
    private Sum sumValue;// Shared Sum object to store the result

    public Summation(int upper, Sum sumValue) {
        this.upper = upper;
        this.sumValue = sumValue;
    }

    @Override
    public void run() {
        int sum = 0;
        for (int i = 1; i <= upper; i++) {
            sum += i;
        }
        // Update the shared Sum object with the calculated result
        sumValue.setSum(sum);
    }
}

public class Driver {
    public static void main(String[] args) {
        if (args.length > 0) {
            int upper;// Variable to store the upper limit
            try {
                upper = Integer.parseInt(args[0]);

                if (upper < 0) {
                    System.err.println("Error: " + args[0] + " must be >= 0.");
                    return;
                }
            } catch (NumberFormatException e) {
                System.err.println("Error: Input must be an integer.");
                return;
            }

             
            // Create a shared Sum object to store the result
            Sum sumObject = new Sum();

            // Create a thread with the Summation task
            Thread thread = new Thread(new Summation(upper, sumObject));

            thread.start();

            try {
                thread.join();
                System.out.println("The sum of numbers up to " + upper + " is " + sumObject.getSum());
            } catch (InterruptedException ie) {
                System.err.println("Thread interrupted: " + ie.getMessage());
            }

        } else {
            System.err.println("Usage: java Driver <integer value>");
        }
    }
}
