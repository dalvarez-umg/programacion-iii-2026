import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class GeneradorClientes {

    public static void generarArchivo(String ruta, int cantidad) {
        Random random = new Random();

        String[] segmentos = {"PREPAGO", "POSTPAGO", "RESIDENCIAL", "PYME", "CORPORATIVO"};
        String[] regiones = {"NORTE", "SUR", "ORIENTE", "OCCIDENTE", "CENTRO"};

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ruta))) {

            writer.write("id,nombre,ingreso,segmento,region,score,deuda,jsonData");
            writer.newLine();

            for (int i = 1; i <= cantidad; i++) {
                double ingreso = generarIngreso(random);
                String segmento = segmentos[random.nextInt(segmentos.length)];
                String region = regiones[random.nextInt(regiones.length)];
                int score = random.nextInt(1000);
                double deuda = random.nextInt(10000);
                String jsonData = generarJsonPesado(random);

                writer.write(
                        i + "," +
                                "Cliente_" + i + "," +
                                ingreso + "," +
                                segmento + "," +
                                region + "," +
                                score + "," +
                                deuda + "," +
                                "\"" + jsonData.replace("\"", "'") + "\""
                );

                writer.newLine();
            }

            System.out.println("Archivo generado correctamente: " + ruta);

        } catch (IOException e) {
            System.out.println("Error generando archivo: " + e.getMessage());
        }
    }

    private static double generarIngreso(Random random) {
        int[] ingresos = {5000, 8000, 10000, 12000, 15000, 18000, 20000, 25000, 30000};
        return ingresos[random.nextInt(ingresos.length)];
    }

    private static String generarJsonPesado(Random random) {
        StringBuilder sb = new StringBuilder();

        sb.append("{");

        for (int i = 0; i < 40; i++) {
            sb.append("\"campo").append(i).append("\":\"");

            for (int j = 0; j < 80; j++) {
                sb.append((char) ('a' + random.nextInt(26)));
            }

            sb.append("\",");
        }

        sb.append("\"historial\":[");

        for (int i = 0; i < 10; i++) {
            sb.append("{")
                    .append("\"evento\":\"evento_").append(i).append("\",")
                    .append("\"monto\":").append(random.nextInt(5000)).append(",")
                    .append("\"estado\":\"ACTIVO\"")
                    .append("}");

            if (i < 9) {
                sb.append(",");
            }
        }

        sb.append("],");
        sb.append("\"observacion\":\"Registro pesado para simular atributo JSON o CLOB\"");

        sb.append("}");

        return sb.toString();
    }
}