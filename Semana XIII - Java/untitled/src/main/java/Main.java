public class Main {
    public static void main(String[] args) {
        ArbolAvl arbol = new ArbolAvl();

        arbol.insertar(new Estudiante(103, "Ana", 89.5));
        arbol.insertar(new Estudiante(101, "Luis", 75.0));
        arbol.insertar(new Estudiante(105, "Carlos", 91.2));
        arbol.insertar(new Estudiante(100, "María", 84.3));
        arbol.insertar(new Estudiante(102, "José", 70.5));
        arbol.insertar(new Estudiante(104, "Andrea", 88.1));
        arbol.insertar(new Estudiante(106, "Pablo", 79.4));

        System.out.println("=== Recorrido InOrden ===");
        arbol.inOrden();

        System.out.println("\n=== Recorrido PreOrden ===");
        arbol.preOrden();

        System.out.println("\n=== Recorrido PostOrden ===");
        arbol.postOrden();

        System.out.println("\nAltura de la raíz: " + arbol.obtenerAlturaRaiz());
        System.out.println("Factor de balance de la raíz: " + arbol.obtenerBalanceRaiz());

        int idBuscado = 104;
        Estudiante encontrado = arbol.buscar(idBuscado);

        System.out.println("\n=== Búsqueda ===");
        if (encontrado != null) {
            System.out.println("Estudiante encontrado:");
            System.out.println(encontrado);
        } else {
            System.out.println("No se encontró estudiante con ID: " + idBuscado);
        }
    }
}