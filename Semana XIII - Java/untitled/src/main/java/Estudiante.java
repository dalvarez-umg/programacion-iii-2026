public class Estudiante {
    int id;
    String nombre;
    double promedio;

    public Estudiante(int id, String nombre, double promedio) {
        this.id = id;
        this.nombre = nombre;
        this.promedio = promedio;
    }

    @Override
    public String toString() {
        return "ID: " + id + " | Nombre: " + nombre + " | Promedio: " + promedio;
    }
}