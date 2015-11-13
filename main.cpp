#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

  if (argc <= 1) {
    return 0;
  }

  const char* grades[] = {
    "A+", "A", "A-",
    "B+", "B", "B-",
    "C+", "C", "C-",
    "D+", "D", "D-",
    "F"
  };

  float total = 0;
  float weight = 0;
  int grade_count = argc - 1;
  int i = 1;

  for (; i < argc; i++) {
    std::string arg(argv[i]);
    if (arg == "-w") {
      weight = std::stof(std::string(argv[i + 1]));
      grade_count -= 2;
      i++;
      continue;
    }
    float at = 4.3;
    int pointer = 0;
    while (strcmp(arg.c_str(), grades[pointer])) {
      at -= 0.3;
      pointer++;
      if (pointer >= argc) {
        at = 0;
        break;
      }
    }
    total += at;
  }

  std::cout << "GPA: " << (total / grade_count) + weight << std::endl;

  return 0;
}
