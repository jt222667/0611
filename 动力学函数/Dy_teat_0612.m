clc;
clear;
tar.POS_e = [1.80 0 1.80]';
tar.ORI_e = cy(pi/2);
RP_data = Module_Lib();
[n, module_raw, install_raw, align_raw, sequence_raw] = generate_valid_config_x(RP_data);
[module_out, install_out, align_out, sequence_out, num_exp, is_valid, ~] = expand_module_units(module_raw(1:n),install_raw(1:n),align_raw(1:n),sequence_raw(1:n),RP_data);
LP = LP_generate(module_out, install_out, align_out, sequence_out, RP_data);
SV = SV_generate(LP);

%%
rb = calc_Dy_0611(LP);


