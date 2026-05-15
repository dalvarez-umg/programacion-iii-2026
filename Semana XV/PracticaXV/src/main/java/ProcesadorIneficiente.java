import java.util.ArrayList;
import java.util.List;

public class ProcesadorIneficiente {

    public static void procesar(List<Cliente> clientes) {

        List<String> tiposCampania = new ArrayList<>();
        List<List<Cliente>> grupos = new ArrayList<>();

        long inicio = System.currentTimeMillis();

        for (Cliente cliente : clientes) {

            String tipo = determinarCampania(cliente);

            int index = -1;

            // BÚSQUEDA LINEAL INEFICIENTE:
            // Busca una campaña recorriendo una lista.
            for (int i = 0; i < tiposCampania.size(); i++) {
                if (tiposCampania.get(i).equals(tipo)) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                tiposCampania.add(tipo);

                List<Cliente> nuevaLista = new ArrayList<>();
                nuevaLista.add(cliente);

                grupos.add(nuevaLista);
            } else {
                grupos.get(index).add(cliente);
            }
        }

        long fin = System.currentTimeMillis();

        System.out.println("\nResumen de campañas generadas:");
        System.out.println("Total de campañas diferentes: " + tiposCampania.size());

        for (int i = 0; i < tiposCampania.size(); i++) {
            System.out.println(tiposCampania.get(i) + ": " + grupos.get(i).size());
        }

        System.out.println("\nTiempo de procesamiento ineficiente: " + (fin - inicio) + " ms");
    }

    private static String determinarCampania(Cliente cliente) {

        String nivelIngreso;

        if (cliente.getIngreso() >= 25000) {
            nivelIngreso = "INGRESO_ALTO";
        } else if (cliente.getIngreso() >= 15000) {
            nivelIngreso = "INGRESO_MEDIO";
        } else if (cliente.getIngreso() >= 10000) {
            nivelIngreso = "INGRESO_BAJO";
        } else {
            nivelIngreso = "NO_APLICA";
        }

        String nivelScore;

        if (cliente.getScore() >= 800) {
            nivelScore = "SCORE_EXCELENTE";
        } else if (cliente.getScore() >= 600) {
            nivelScore = "SCORE_BUENO";
        } else if (cliente.getScore() >= 400) {
            nivelScore = "SCORE_REGULAR";
        } else {
            nivelScore = "SCORE_RIESGO";
        }

        String nivelDeuda;

        if (cliente.getDeuda() >= 7000) {
            nivelDeuda = "DEUDA_ALTA";
        } else if (cliente.getDeuda() >= 3000) {
            nivelDeuda = "DEUDA_MEDIA";
        } else {
            nivelDeuda = "DEUDA_BAJA";
        }

        return cliente.getSegmento()
                + "_"
                + cliente.getRegion()
                + "_"
                + nivelIngreso
                + "_"
                + nivelScore
                + "_"
                + nivelDeuda;
    }
}