import java.util.Map;
import java.util.TreeMap;

class Student {
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
    public String toString() {
        return studentId + " - " + fullName +
                " | GPA: " + gpa +
                " | Score: " + skillScore;
    }
}

public class TreeMapExampleMain {
    public static void main(String[] args) {

        TreeMap<Integer, Student> ranking = new TreeMap<>();

        ranking.put(120, new Student(1001, "Juan Perez", 85.5, 120));
        ranking.put(200, new Student(1002, "Ana Lopez", 91.2, 200));
        ranking.put(95,  new Student(1003, "Carlos Ruiz", 78.3, 95));
        ranking.put(160, new Student(1004, "Maria Gomez", 88.7, 160));

        System.out.println("=== Ranking Ordenado por Skill Score ===");

        for (Map.Entry<Integer, Student> entry : ranking.entrySet()) {
            System.out.println(entry.getValue());
        }

        System.out.println("\n=== Buscar Score 160 ===");
        System.out.println(ranking.get(160));

        System.out.println("\n=== Mejor Score ===");
        System.out.println(ranking.lastEntry().getValue());

        System.out.println("\n=== Peor Score ===");
        System.out.println(ranking.firstEntry().getValue());
    }
}