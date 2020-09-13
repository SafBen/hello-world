package xception.none;

class SomeOtherClass {
    private final UsefulClass uc = new UsefulClass();
    
    int someOtherMethod(int i) {
        try {
            boolean borked = uc.usefulMethod(i);
        } catch (MyUsefulException e) {
            System.err.println(e.getMessage());
        }
        // ignore returned diagnostic value, because we can...
        return uc.getI();
    }
}
