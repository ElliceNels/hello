import java.util.Scanner;

public final class IOHandler {
    private static final Scanner SCANNER = new Scanner(System.in);

    private IOHandler() {}

    public static String commandLineInput() {
        String userInput = "";
        while (userInput.isEmpty()) {
            if (!SCANNER.hasNextLine()) {
                throw new IllegalStateException("Input ended before a non-empty value was provided");
            }
            userInput = cleanUserInput(SCANNER.nextLine());
        }
        return userInput;
    }

    public static String cleanUserInput(String dirtyInput) {
        return dirtyInput.strip().toLowerCase();
    }
}
