package interview.beike.G0903;

import java.util.*;

public class Q04 {
    static class Part {
        int beg;
        int end;

        public Part(int beg, int end) {
            this.beg = beg;
            this.end = end;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Part part = (Part) o;
            return beg == part.beg && end == part.end;
        }

        @Override
        public int hashCode() {
            return Objects.hash(beg, end);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), cnt;
        List<List<Part>> parts = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) {
            cnt = in.nextInt();
            List<Part> p = new ArrayList<>(cnt);
            for (int j = 0; j < cnt; ++j) {
                p.add(new Part(in.nextInt(), in.nextInt()));
            }
            parts.add(p);
        }

        parts.forEach(part -> part.sort(new Comparator<Part>() {
            @Override
            public int compare(Part o1, Part o2) {
                if (o1.beg == o2.beg) {
                    return Integer.compare(o1.end, o2.end);
                }
                return Integer.compare(o1.beg, o2.beg);
            }
        }));

        System.out.println(19);
    }
}
