package xception.none;

class UsefulClass {
    private int i = 0;
    
    /**
     * This method only works for values i >= 0.
     * Return value indicates whether the argument receives an acceptable
     * value for i. An unacceptable value of i should not be used in any application.
     * There! You have been warned...
     * @param i Must be >= 0.
     * @return true if i >= 0; false otherwise.
     */
    boolean usefulMethod(int i) throws MyUsefulException {
        if (i < 0) {
            throw new MyUsefulException(
                    "Hey! i = "
                            + i +", should be >=0");
        } else {
            return true;
        }
    }
    
    /**
     * Getter method for i.
     * @return Value of i.
     */
    int getI() {
        return i;
    }
}
