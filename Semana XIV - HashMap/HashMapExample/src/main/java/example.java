import java.util.HashMap;

public class example {

    public static void main(String[] args) {

        // HashMap<Clave, Valor>
        HashMap<Integer, Estudiante> estudiantes = new HashMap<>();

        // INSERTAR
        estudiantes.put(
                1001,
                new Estudiante(
                        1001,
                        "Juan Perez"
                )
        );

        estudiantes.put(
                1002,
                new Estudiante(
                        1002,
                        "Ana Lopez"
                )
        );

        // BUSCAR
        int buscarId = 1001;

        if (estudiantes.containsKey(buscarId)) {

            Estudiante estudiante = estudiantes.get(buscarId);

            System.out.println("=== ESTUDIANTE ENCONTRADO ===");
            System.out.println(estudiante);

        } else {

            System.out.println("No existe estudiante.");
        }

        // ELIMINAR
        int eliminarId = 1002;

        if (estudiantes.containsKey(eliminarId)) {

            estudiantes.remove(eliminarId);

            System.out.println("\nEstudiante eliminado.");

        } else {

            System.out.println("No existe estudiante para eliminar.");
        }

        // MOSTRAR HASHMAP
        System.out.println("\n=== ESTUDIANTES ACTUALES ===");

        for (Integer key : estudiantes.keySet()) {

            System.out.println("-------------------");
            System.out.println(estudiantes.get(key));
        }

        // ESTADISTICAS
        System.out.println("\n=== ESTADISTICAS ===");
        System.out.println("Total estudiantes: " + estudiantes.size());
    }
}