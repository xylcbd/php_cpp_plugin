#ifndef PHP_ALLEN_H
    #define PHP_ALLEN_H 1
    #define PHP_HW_BEAUTY_VERSION "1.0"
    #define PHP_HW_BEAUTY_EXTNAME "allen"
    PHP_FUNCTION(say);
    extern zend_module_entry allen_module_entry;
    #define phpext_allen_ptr &allen_module_entry
#endif
