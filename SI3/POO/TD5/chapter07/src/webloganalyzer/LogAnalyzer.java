package webloganalyzer;

/**
 * Read web server data and analyse hourly access patterns.
 * 
 * @author David J. Barnes and Michael Kölling.
 * @version    2016.02.29
 * @author Safwane Benidir
 */
class LogAnalyzer {
    // Where to calculate the hourly access counts.
    private final int[] hourCounts;
    // Use a LogfileReader to access the data.
    private final LogfileReader reader;

    /**
     * Create an object to analyze hourly web accesses.
     */
    LogAnalyzer() {
        // Create the array object to hold the hourly
        // access counts.
        hourCounts = new int[24];
        // Create the reader to obtain the data.
        reader = new LogfileReader();
    }

    /**
     * Analyze the hourly access data from the log file.
     */
    void analyzeHourlyData() {
        while (reader.hasNext()) {
            LogEntry entry = reader.next();
            int hour = entry.getHour();
            hourCounts[hour]++;
        }
    }

    /**
     * Print the hourly counts.
     * These should have been set with a prior
     * call to analyzeHourlyData.
     */
    void printHourlyCounts() {
        System.out.println("Hr: Count");
        for (int hour = 0; hour < hourCounts.length; hour++) {
            System.out.println(hour + ": " + hourCounts[hour]);
        }
    }
    
    /**
     * Print the lines of data read by the LogfileReader
     */
    private void printData() {
        reader.printData();
    }

    int[] busiestHour(){
        int max=0;
        int h=0;
        int[] res = new int[2];
        for (int i=0;i<hourCounts.length;i++){
            if (hourCounts[i]>max){
                max = hourCounts[i];
                h = i;
            }
        }
        res[0]=h;
        res[1]=max;
        return res;
    }

    int[] quietestHour(){
        int min=1000000;
        int h=0;
        int[] res = new int[2];
        for (int i=0;i<hourCounts.length;i++){
            if (hourCounts[i]<min){
                min = hourCounts[i];
                h = i;
            }
        }
        res[0]=h;
        res[1]=min;
        return res;
    }

    int[] busiestTwoHours(){
        int max=0;
        int h=0;
        int[] res = new int[2];
        for (int i=0;i<hourCounts.length;i++){
            if (hourCounts[i]>max){
                max = hourCounts[i];
                h = i;
            }
        }
        res[0]=h;
        res[1]=max+hourCounts[h+1];
        return res;
    }

}
