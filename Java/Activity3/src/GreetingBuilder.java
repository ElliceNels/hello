import java.util.HashMap;
import java.util.Map;

public final class GreetingBuilder {
    private static final String DEFAULT_GREETING = "Hello World";
    private static final Map<String, String> GREETINGS = new HashMap<>();

    static {
        GREETINGS.put("formal", "Hello There");
        GREETINGS.put("friendly", "Hiya");
        GREETINGS.put("enthusiastic", "Ayeeee!! What is upp!!");
    }

    private GreetingBuilder() {
    }

    public static String getPersonalisedGreeting(String name, String greeting) {
        return name + ", " + greeting;
    }

    public static String getGreeting(String greetingType) {
        return GREETINGS.getOrDefault(greetingType, DEFAULT_GREETING);
    }

    public static String[] getAllGreetings() {
        return GREETINGS.keySet().toArray(new String[0]);
    }
}
