import java.util.Map;
import java.util.Scanner;

public class Main2 {
    public static String DEFAULT_GREETING = "Hello World";
    public static Scanner scanner = new Scanner(System.in);
    public static Map<String, String> greetings = Map.of(
            "formal", "Hello There",
            "friendly", "Hiya",
            "Enthusiastic", "Ayeeee!! What is upp!!"
    );

    public static String getGreeting(String greeting) {
        greeting = greeting.toLowerCase().strip();
        if (!greetings.containsKey(greeting)){
            return DEFAULT_GREETING;
        } else {
            return greetings.get(greeting);
        }
    }

    public static String getInput(){
        String input = null;
        while (input == null) {
            input = scanner.next();
        }
        return input;
    }

    public static String getPersonalisedGreeting(String name, String greeting) {
        return name + ", " + greeting;
    }

    public static void main(String[] args) {
        System.out.println("Enter username: ");
        String name = getInput();

        System.out.println("Enter greeting type [formal, friendly, enthusiastic]. Type anything else for default greeting: ");
        String greeting = getGreeting(getInput());

        System.out.printf(getPersonalisedGreeting(name, greeting));
    }
}
