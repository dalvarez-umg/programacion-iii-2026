import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProcesadorMalo {

    public static List<Cliente> cargarTodosLosClientes(String ruta) {
        List<Cliente> clientes = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(ruta))) {

            String linea;
            reader.readLine();

            while ((linea = reader.readLine()) != null) {
                String[] partes = linea.split(",", 8);

                int id = Integer.parseInt(partes[0]);
                String nombre = partes[1];
                double ingreso = Double.parseDouble(partes[2]);
                String segmento = partes[3];
                String region = partes[4];
                int score = Integer.parseInt(partes[5]);
                double deuda = Double.parseDouble(partes[6]);
                String jsonData = partes[7];

                Cliente cliente = new Cliente(id, nombre, ingreso, segmento, region, score, deuda, jsonData);

                // MALA PRÁCTICA INTENCIONAL:
                // Se cargan todos los clientes en memoria.
                clientes.add(cliente);
            }

        } catch (IOException e) {
            System.out.println("Error leyendo archivo: " + e.getMessage());
        }

        return clientes;
    }
}