import java.util.ArrayList;
import java.util.List;

public class GrahamScan {

  class Point {

    int x;
    int y;

    Point() {
      x = 0;
      y = 0;
    }

    Point(int a, int b) {
      x = a;
      y = b;
    }
  }

  class Pair {

    double first;
    int second;

    Pair() {
      first = 0.0;
      second = 0;
    }

    Pair(double a, int b) {
      first = a;
      second = b;
    }
  }

  public List<Point> process(Point[] points) {
    int t = 0;
    final int n = points.length;
    List<Point> ans = new ArrayList<>();
    if (n > 1) {
      for (int i = 1; i < n; i++) {
        if (smaller(points[i], points[t])) {
          t = i;
        }
      }
      Point sw = points[t];
      points[t] = points[0];
      points[0] = sw;
      List<Pair> rem = new ArrayList<>(n);
      double min = calc(points[1], points[0]);
      double max = calc(points[1], points[0]);
      for (int i = 1; i < n; i++) {
        rem.add(new Pair(calc(points[i], points[0]), i));
        min = Math.min(min, rem.get(rem.size() - 1).first);
        max = Math.max(max, rem.get(rem.size() - 1).first);
      }
      rem.sort((a, b) -> Double.compare(a.first, b.first));
      int ind = 0;
      while (ind < rem.size() - 1) {
        if (little(rem.get(ind).first, rem.get(ind + 1).first)) {
          if (points[rem.get(ind).second].x > points[rem.get(ind + 1).second].x) {
            rem.remove(ind + 1);
          } else {
            rem.remove(ind);
          }
        } else {
          ind++;
        }
      }
      ans.add(points[0]);
      ans.add(points[rem.get(0).second]);
      for (int i = 1; i < rem.size(); i++) {
        while (rotate(ans.get(ans.size() - 2), ans.get(ans.size() - 1),
            points[rem.get(i).second])) {
          ans.remove(ans.size() - 1);
        }
        ans.add(points[rem.get(i).second]);
      }
    } else {
      ans.add(points[0]);
    }
    return ans;
  }

  private boolean little(double x, double y) {
    return x - y <= 0.000001 && x - y >= -0.000001;
  }

  private boolean smaller(Point p1, Point p2) {
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
  }

  private double calc(Point p1, Point p2) {
    return (p1.y - p2.y) / Math.sqrt((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x));
  }

  private boolean rotate(Point p1, Point p2, Point p3) {
    return (p3.y - p1.y) * (p2.x - p1.x) < (p2.y - p1.y) * (p3.x - p1.x);
  }

}
