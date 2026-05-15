import java.util.List;

public class Main {

    public static void main(String[] args) {

        String archivo = "clientes.csv";
        int cantidadClientes = 2_000_000;

        System.out.println("======================================");
        System.out.println("LABORATORIO: PROCESAMIENTO MASIVO");
        System.out.println("======================================");

        System.out.println("\nGenerando archivo...");
        long inicioGeneracion = System.currentTimeMillis();

        GeneradorClientes.generarArchivo(archivo, cantidadClientes);

        long finGeneracion = System.currentTimeMillis();
        System.out.println("Tiempo de generación: " + (finGeneracion - inicioGeneracion) + " ms");

        mostrarMemoria();

        System.out.println("\nCargando TODOS los clientes en memoria...");
        long inicioCarga = System.currentTimeMillis();

        List<Cliente> clientes = ProcesadorMalo.cargarTodosLosClientes(archivo);

        long finCarga = System.currentTimeMillis();

        System.out.println("Clientes cargados en memoria: " + clientes.size());
        System.out.println("Tiempo de carga: " + (finCarga - inicioCarga) + " ms");

        mostrarMemoria();

        System.out.println("\nProcesando con estructura INEFICIENTE...");
        ProcesadorIneficiente.procesar(clientes);

        mostrarMemoria();

        System.out.println("\nFin del programa.");
    }

    private static void mostrarMemoria() {
        Runtime runtime = Runtime.getRuntime();

        long memoriaUsada = runtime.totalMemory() - runtime.freeMemory();
        long memoriaTotal = runtime.totalMemory();
        long memoriaMaxima = runtime.maxMemory();

        System.out.println("\nMemoria JVM:");
        System.out.println("Usada : " + (memoriaUsada / 1024 / 1024) + " MB");
        System.out.println("Total : " + (memoriaTotal / 1024 / 1024) + " MB");
        System.out.println("Máxima: " + (memoriaMaxima / 1024 / 1024) + " MB");
    }
}
