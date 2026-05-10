public class Estudiante {
    int studentId;
    String fullName;

    public Estudiante(int studentId,
                      String fullName) {

        this.studentId = studentId;
        this.fullName = fullName;
    }

    @Override
    public String toString() {
        return "ID: " + studentId +
                "\nNombre: " + fullName;
    }
}
