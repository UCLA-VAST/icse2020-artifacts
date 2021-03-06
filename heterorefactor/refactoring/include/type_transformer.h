#pragma once

#include "ast_utils.h"
#include "misc_utils.h"

#include "rose.h"
#include "wholeAST.h"
#include "sageInterface.h"
#include "roseAdapter.h"

#include <set>
#include <map>
#include <vector>
#include <utility>

class TypeTransformer {
public:
    TypeTransformer(SgProject* project, misc_utils::RefactorType t);
    void set_exclusion(const std::set<SgNode *> *excluded);
    void set_varmap(std::map<std::string, std::string>);
    void transform(void);

    SgType *get_transformation_fp(SgScopeStatement *scope);
    SgType *get_transformation_i(SgScopeStatement *scope, SgName var_name);
    SgType *get_transformation_of(SgPointerType *type,
            SgScopeStatement *scope = NULL);

protected:
    void transform_func_return(void);
    void transform_func_param(void);
    void transform_var_decl(void);
    void transform_typecast(void);

    void transform_binary_operations(void);

    SgType *recursive_transform(SgType *type, SgScopeStatement *scope);
    SgType *recursive_transform_i(SgType *type, SgScopeStatement *scope, SgName var_name);

    SgProject *m_project;
    misc_utils::RefactorType m_type;
    SgType *m_transform_type;
    const std::set<SgNode *> *m_excluded;

    std::map<SgPointerType *, SgType *> m_mapping_to_index;
    std::map<std::string, std::string> var_name_to_type_map;
};
