function rb = calc_Dy_0611(LP)

[sub_module, sub_align] = split_joint_chain(LP.module, LP.align);

rb(LP.num_joint-1) = struct('m', [], 'rc', [], 'I', []);

for i = 1:LP.num_joint-1
    [rb(i).m, rb(i).rc, rb(i).I] = calc_rigid_body_params_0318(sub_module{i}, sub_align{i});
end

end