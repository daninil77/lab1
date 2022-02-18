#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

enum TIPE {lecture=0,practice=1,laboratory=2,exam=3};


struct  occupation
{
    int n;
    std::string predmet;
    TIPE tipe;
    int aud;
};

std::vector<std::string> split(const std::string &str, char delim)
{
std::vector<std::string> tokens;

if (!str.empty())
{
size_t start = 0, end;
do {
end = str.find(delim, start); // поменял местами метод push_back и присвоение новой велечины end
tokens.push_back(str.substr(start, (end - start)));
start = end + 1;
} while (end != std::string::npos);
}

return tokens;
}
int main()
{
  // Считывать файл в цикле и сохранять занятия в вектор
    std::vector<occupation> zanytiya;

  std::fstream fin("F:\\qt\\lab_1\\occupation.csv");
  if (fin.is_open())
  {
      std::string line;
      while (getline(fin, line))
      {
       auto v = split(line, ';');

       occupation zan;
       zan.n = std::stoi( v[0]);
       zan.predmet = (v[1]);
       zan.tipe = static_cast<TIPE>(std::stoi(v[2]));
       zan.aud = std::stoi(v[3]);

       zanytiya.push_back(zan);
      }
  }
fin.close();
  // Вывод занятий из вектора
  for (const auto &c : zanytiya)
  {   if ((c.tipe == 3) && (c.aud == 1205)){
      std::cout << c.n << "," << c.predmet << "," << c.tipe << "," << c.aud << std::endl;

  }
}
  // Сортировка

      std::sort(zanytiya.begin(), zanytiya.end(),[](const  occupation &c1, const  occupation &c2){
      return c1.aud > c2.aud;
  });

  // Вывод в файл
  std::ofstream fout("F:\\qt\\lab_1\\new_occupation.csv");
  for (const auto &c : zanytiya){
        fout << c.n << "," << c.predmet << "," << c.tipe << "," << c.aud << std::endl;
  }
      fout.close();
    return 0;

}
