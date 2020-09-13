import java.util.Scanner;
import java.io.InputStream;
import java.io.ByteArrayInputStream;


class Main{
    public static String saisie;
    static void ecrire(){
        Scanner scanner = new Scanner(System.in);
        saisie = scanner.nextLine();
    }
    public static void main(String[] args){
        String data = "Hello, World!\r\n";
        InputStream stdin = System.in;
        try {
            System.setIn(new ByteArrayInputStream(data.getBytes()));
            ecrire();
            System.out.println(saisie);
        } finally {
            System.setIn(stdin);
//"2Tr 3Ca 5Tr 10Tr AsCa"
        }
        scanner.close();
    }
}



