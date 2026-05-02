import java.util.TreeSet;

class Student implements Comparable<Student> {
    int studentId;
    String fullName;
    double gpa;
    int skillScore;

    public Student(int studentId, String fullName, double gpa, int skillScore) {
        this.studentId = studentId;
        this.fullName = fullName;
        this.gpa = gpa;
        this.skillScore = skillScore;
    }

    @Override
    public int compareTo(Student other) {
        if (this.skillScore != other.skillScore) {
            return Integer.compare(this.skillScore, other.skillScore);
        }
        return Integer.compare(this.studentId, other.studentId);
    }

    @Override
    public String toString() {
        return studentId + " - " + fullName +
                " | GPA: " + gpa +
                " | Score: " + skillScore;
    }
}

public class TreeSetExample_Main {
    public static void main(String[] args) {

        TreeSet<Student> ranking = new TreeSet<>();

        ranking.add(new Student(1001, "Juan Perez", 85.5, 120));
        ranking.add(new Student(1002, "Ana Lopez", 91.2, 200));
        ranking.add(new Student(1003, "Carlos Ruiz", 78.3, 95));
        ranking.add(new Student(1004, "Maria Gomez", 88.7, 160));
        ranking.add(new Student(1005, "Luis Ramirez", 80.0, 120));

        System.out.println("=== Ranking Ordenado ===");

        for (Student student : ranking) {
            System.out.println(student);
        }

        System.out.println("\n=== Mejor Score ===");
        System.out.println(ranking.last());

        System.out.println("\n=== Peor Score ===");
        System.out.println(ranking.first());
    }
}