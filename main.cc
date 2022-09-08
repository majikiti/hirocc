#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline constexpr string_view version = "hirocc v0.0";

auto help() -> void {
  cout << version << endl <<
    "\n"
    "Usage:\n"
    "  hirocc [options] [targets]\n"
    "\n"
    "Options:\n"
    "  -h: show this help\n"
    "  -v: show version\n"
    "\n";
}

auto ver() -> void {
  cout << version << endl;
}

auto main(int argc, char* argv[]) -> int {
  vector<string> args{argv + 1, argv + argc};
  vector<string> opts;
  vector<string> paths;

  for(size_t i = 0; i < args.size(); i++) {
    auto arg = args[i];
    if(arg[0] == '-') {
      opts.push_back(arg);
    } else {
      paths.push_back(arg);
    }
  }

  if(find(opts.begin(), opts.end(), "-h") != opts.end()) {
    help();
    return 0;
  }
  if(find(opts.begin(), opts.end(), "-v") != opts.end()) {
    ver();
    return 0;
  }

  if(!paths.size()) {
    help();
    return 0;
  }

  size_t errn = 0;
  string buf;
  for(auto path: paths) {
    if(!filesystem::exists(path)) {
      cerr << "File not found: "s << path << endl;
      errn++;
      continue;
    }

    ifstream fin{path};
    cout << "----"s << path << "----"s << endl;

    while(getline(fin, buf)) {
      cout << buf << endl;
    }

    cout << "----"s << path << "----"s << endl;
  }

  if(errn) {
    cerr << "There are "s << errn << " errors."s << endl;
  }
  cout << "done"s << endl;
}
