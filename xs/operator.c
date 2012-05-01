bool tora_op_gt(SV* lhs, SV*rhs) {
    value_type_t lhs_t = tora_detect_value_type(lhs);
    value_type_t rhs_t = tora_detect_value_type(rhs);

    if (lhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as left side value in greater than operator.");
    }
    if (rhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as right side value in greater than operator.");
    }
    if (lhs_t == VALUE_TYPE_INT || lhs_t == VALUE_TYPE_DOUBLE) {
        return SvNV(lhs) > SvNV(rhs) ? TRUE : FALSE;
    } else if (lhs_t == VALUE_TYPE_STR) {
        char * lhs_c = SvPV_nolen(lhs);
        char * rhs_c = SvPV_nolen(rhs);
        return strGT(lhs_c, rhs_c);
    } else {
        croak("greater than operator does not support this type: %s", tora_stringify_type(lhs_t));
    }
    abort();
}
bool tora_op_lt(SV* lhs, SV*rhs) {
    value_type_t lhs_t = tora_detect_value_type(lhs);
    value_type_t rhs_t = tora_detect_value_type(rhs);

    if (lhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as left side value in less than operator.");
    }
    if (rhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as right side value in less than operator.");
    }
    if (lhs_t == VALUE_TYPE_INT || lhs_t == VALUE_TYPE_DOUBLE) {
        return SvNV(lhs) < SvNV(rhs) ? TRUE : FALSE;
    } else if (lhs_t == VALUE_TYPE_STR) {
        char * lhs_c = SvPV_nolen(lhs);
        char * rhs_c = SvPV_nolen(rhs);
        return strLT(lhs_c, rhs_c);
    } else {
        croak("less than operator does not support this type: %s", tora_stringify_type(lhs_t));
    }
    abort();
}
bool tora_op_le(SV* lhs, SV*rhs) {
    value_type_t lhs_t = tora_detect_value_type(lhs);
    value_type_t rhs_t = tora_detect_value_type(rhs);

    if (lhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as left side value in less than or equals operator.");
    }
    if (rhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as right side value in less than or equals operator.");
    }
    if (lhs_t == VALUE_TYPE_INT || lhs_t == VALUE_TYPE_DOUBLE) {
        return SvNV(lhs) <= SvNV(rhs) ? TRUE : FALSE;
    } else if (lhs_t == VALUE_TYPE_STR) {
        char * lhs_c = SvPV_nolen(lhs);
        char * rhs_c = SvPV_nolen(rhs);
        return strLE(lhs_c, rhs_c);
    } else {
        croak("less than or equals operator does not support this type: %s", tora_stringify_type(lhs_t));
    }
    abort();
}
bool tora_op_ge(SV* lhs, SV*rhs) {
    value_type_t lhs_t = tora_detect_value_type(lhs);
    value_type_t rhs_t = tora_detect_value_type(rhs);

    if (lhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as left side value in greater than or equals operator.");
    }
    if (rhs_t == VALUE_TYPE_UNDEF) {
        croak("You cannot use undefined value as right side value in greater than or equals operator.");
    }
    if (lhs_t == VALUE_TYPE_INT || lhs_t == VALUE_TYPE_DOUBLE) {
        return SvNV(lhs) >= SvNV(rhs) ? TRUE : FALSE;
    } else if (lhs_t == VALUE_TYPE_STR) {
        char * lhs_c = SvPV_nolen(lhs);
        char * rhs_c = SvPV_nolen(rhs);
        return strGE(lhs_c, rhs_c);
    } else {
        croak("greater than or equals operator does not support this type: %s", tora_stringify_type(lhs_t));
    }
    abort();
}

