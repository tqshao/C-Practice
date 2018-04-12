#include <iostream>
#include <string>
#include "chrono_thirdparty/rapidjson/document.h"
#include "chrono_thirdparty/rapidjson/filereadstream.h"

using namespace rapidjson;

int main(){
  std::string filename("PitmanArm.json");
  FILE* fp = fopen(filename.c_str(), "r");

  char readBuffer[65536];
  FileReadStream is(fp, readBuffer, sizeof(readBuffer));

  fclose(fp);

  Document d;
  d.ParseStream<ParseFlag::kParseCommentsFlag>(is);

  double max_steering_angle = d["Revolute Joint"]["Maximum Angle"].GetDouble();
  std::cout << "The max steering angle is: " << max_steering_angle << std::endl;

  return 0;
}
