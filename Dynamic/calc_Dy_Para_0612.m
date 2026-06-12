function rb = calc_Dy_Para_0612(LP)
[sub_module, sub_align] = split_joint_chain(LP.module, LP.align);
rb(LP.num_joint) = struct('m', [], 'rc', [], 'I', []);
for i = 1:LP.num_joint-1
    [rb(i).m, rb(i).rc, rb(i).I] = calc_rigid_body_params_0318(sub_module{i}, sub_align{i});
end
module_end = LP.module(end);
rb(end).m = LP.module_mass_dist(module_end);
rb(end).rc = LP.module_COM_dist(:,module_end);
rb(end).I = LP.module_inertia_dist(:,:,module_end);
end