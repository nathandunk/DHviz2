import json

num_joints = 3

params_file = open("Params.json", "r")
params_data = params_file.read()
params_file.close()
params_json = json.loads(params_data)

params_hpp = open("Params.hpp", "w")

prefixes = ["Ic", "Pc", "m"]
suffixes = [["xx", "xy", "xz", "yy", "yz", "zz"],
            ["x", "y", "z"],
            [""]]

params_hpp.writelines("#pragma once\n\n")

for i in range(0,num_joints):
    joint_num = params_json["joints"][i]["jointNum"]
    params_hpp.writelines("// Joint " + str(joint_num) + "\n\n")
    for num, prefix in enumerate(prefixes):
        for suffix in suffixes[num]:
            val = params_json["joints"][i][prefix + suffix]
            params_hpp.writelines("constexpr double " + prefix + str(joint_num) + suffix + " = " + str(val) + ";\n")
        params_hpp.writelines("\n")