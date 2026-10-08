//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main1 {
    public static String greeting = "Hello World";

    public static String getGreeting() {
        return greeting;
    }

    public static void main(String[] args) {
        System.out.printf(getGreeting());
    }
}