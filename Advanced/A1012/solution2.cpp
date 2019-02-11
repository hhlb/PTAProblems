#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

struct Student {
  int id, C, M, E, A;
  int a, c, m, e;
} stu[3000];

bool cmp1(Student s1, Student s2) {
  if (s1.A == s2.A) {
    if (s1.C == s2.C) {
      if (s1.M == s2.M) {
        if (s1.E == s2.E) {
          return s1.id < s2.id;
        }
        return s1.E > s2.E;
      }
      return s1.M > s2.M;
    }
    return s1.C > s2.C;
  }
  return s1.A > s2.A;
}

bool cmp2(Student s1, Student s2) {
  if (s1.C == s2.C) {
    if (s1.M == s2.M) {
      if (s1.E == s2.E) {
        return s1.id < s2.id;
      }
      return s1.E > s2.E;
    }
    return s1.M > s2.M;
  }
  return s1.C > s2.C;
}

bool cmp3(Student s1, Student s2) {
  if (s1.M == s2.M) {
    if (s1.E == s2.E) {
      return s1.id < s2.id;
    }
    return s1.E > s2.E;
  }
  return s1.M > s2.M;
}

bool cmp4(Student s1, Student s2) {
  if (s1.E == s2.E) {
    return s1.id < s2.id;
  }
  return s1.E > s2.E;
}

int main() {
  int M, N;
  map<int, Student> mmp;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    Student student;
    // int id, C, M, E;
    scanf("%d%d%d%d", &student.id, &student.C, &student.M, &student.E);
    student.A = student.C + student.M + student.E;
    stu[i] = student;
  }

  sort(stu, stu + N, cmp1);
  stu[0].a = 1;
  for (int i = 1; i < N; i++) {
    if (stu[i].A == stu[i - 1].A)
      stu[i].a = stu[i - 1].a;
    else
      stu[i].a = i + 1;
  }
  sort(stu, stu + N, cmp2);
  stu[0].c = 1;
  for (int i = 1; i < N; i++) {
    if (stu[i].C == stu[i - 1].C)
      stu[i].c = stu[i - 1].c;
    else
      stu[i].c = i + 1;
  }
  sort(stu, stu + N, cmp3);
  stu[0].m = 1;
  for (int i = 1; i < N; i++) {
    if (stu[i].M == stu[i - 1].M)
      stu[i].m = stu[i - 1].m;
    else
      stu[i].m = i + 1;
  }
  sort(stu, stu + N, cmp4);
  stu[0].e = 1;
  for (int i = 1; i < N; i++) {
    if (stu[i].E == stu[i - 1].E)
      stu[i].e = stu[i - 1].e;
    else
      stu[i].e = i + 1;
  }
  for (int i = 0; i < N; i++) mmp[stu[i].id] = stu[i];

  for (int i = 0; i < M; i++) {
    int id;
    scanf("%d", &id);
    map<int, Student>::iterator find = mmp.find(id);
    if (find == mmp.end()) {
      printf("N/A\n");
    } else {
      if (find->second.a <= find->second.c &&
          find->second.a <= find->second.m && find->second.a <= find->second.e)
        printf("%d A\n", find->second.a);
      else if (find->second.c <= find->second.a &&
               find->second.c <= find->second.m &&
               find->second.c <= find->second.e)
        printf("%d C\n", find->second.c);
      else if (find->second.m <= find->second.a &&
               find->second.m <= find->second.c &&
               find->second.m <= find->second.e)
        printf("%d M\n", find->second.m);
      else if (find->second.e <= find->second.a &&
               find->second.e <= find->second.m &&
               find->second.e <= find->second.c)
        printf("%d E\n", find->second.e);
    }
  }
  return 0;
}