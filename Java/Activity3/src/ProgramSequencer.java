import java.util.Arrays;

public final class ProgramSequencer {
    private ProgramSequencer() {}

    public static void sequenceProgram() {
        System.out.println("What's your name?: ");
        String name = IOHandler.commandLineInput();
        System.out.println("Choose greeting type! " + Arrays.toString(GreetingBuilder.getAllGreetings())
                + ". Type anything else for default greeting:");
        String greeting = GreetingBuilder.getGreeting(IOHandler.commandLineInput());
        System.out.println(GreetingBuilder.getPersonalisedGreeting(name, greeting));
    }
}
