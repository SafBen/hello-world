package webloganalyzer;

class Main{
    public static void main(String[] args){
        LogAnalyzer analyzer = new LogAnalyzer();
        analyzer.analyzeHourlyData();
        int[] busiest = analyzer.busiestHour();
        System.out.println(busiest[0] + " is busiest hour with " + busiest[1] + " counts");
    }
}