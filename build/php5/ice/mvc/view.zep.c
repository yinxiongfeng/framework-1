
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"


/**
 * View is a class for working with the "view" portion of the model-view-controller pattern.
 *
 * @package     Ice/View
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Mvc_View) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Mvc, View, ice, mvc_view, ice_arr_ce, ice_mvc_view_method_entry, 0);

	zend_declare_property_null(ice_mvc_view_ce, SL("engines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("layoutsDir"), "layouts/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_mvc_view_ce, SL("partialsDir"), "partials/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_mvc_view_ce, SL("file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(ice_mvc_view_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_mvc_view_ce TSRMLS_CC, 1, ice_mvc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Mvc_View, setEngines) {

	zval *engines;

	zephir_fetch_params(0, 1, 0, &engines);



	zephir_update_property_this(this_ptr, SL("engines"), engines TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, setContent) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_this(this_ptr, SL("content"), content TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getContent) {

	

	RETURN_MEMBER(this_ptr, "content");

}

PHP_METHOD(Ice_Mvc_View, setMainView) {

	zval *mainView;

	zephir_fetch_params(0, 1, 0, &mainView);



	zephir_update_property_this(this_ptr, SL("mainView"), mainView TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getMainView) {

	

	RETURN_MEMBER(this_ptr, "mainView");

}

PHP_METHOD(Ice_Mvc_View, setLayoutsDir) {

	zval *layoutsDir;

	zephir_fetch_params(0, 1, 0, &layoutsDir);



	zephir_update_property_this(this_ptr, SL("layoutsDir"), layoutsDir TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getLayoutsDir) {

	

	RETURN_MEMBER(this_ptr, "layoutsDir");

}

PHP_METHOD(Ice_Mvc_View, setPartialsDir) {

	zval *partialsDir;

	zephir_fetch_params(0, 1, 0, &partialsDir);



	zephir_update_property_this(this_ptr, SL("partialsDir"), partialsDir TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getPartialsDir) {

	

	RETURN_MEMBER(this_ptr, "partialsDir");

}

PHP_METHOD(Ice_Mvc_View, setViewsDir) {

	zval *viewsDir;

	zephir_fetch_params(0, 1, 0, &viewsDir);



	zephir_update_property_this(this_ptr, SL("viewsDir"), viewsDir TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getViewsDir) {

	

	RETURN_MEMBER(this_ptr, "viewsDir");

}

PHP_METHOD(Ice_Mvc_View, setFile) {

	zval *file;

	zephir_fetch_params(0, 1, 0, &file);



	zephir_update_property_this(this_ptr, SL("file"), file TSRMLS_CC);

}

PHP_METHOD(Ice_Mvc_View, getFile) {

	

	RETURN_MEMBER(this_ptr, "file");

}

PHP_METHOD(Ice_Mvc_View, setSilent) {

	zval *silent;

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_this(this_ptr, SL("silent"), silent TSRMLS_CC);

}

/**
 * View constructor. Set the file and vars.
 *
 * @param string file
 * @param array data
 */
PHP_METHOD(Ice_Mvc_View, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = ZEPHIR_GLOBAL(global_null);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("file"), file TSRMLS_CC);
	}
	ZEPHIR_CALL_PARENT(NULL, ice_mvc_view_ce, this_ptr, "__construct", &_0, 5, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get registered engines.
 */
PHP_METHOD(Ice_Mvc_View, getEngines) {

	zval *_8$$6 = NULL, *_10$$8 = NULL;
	HashTable *_5;
	HashPosition _4;
	zval *ext = NULL, *engine = NULL, *_0, *_3, **_6, *_1$$3, *_2$$3, *_7$$6 = NULL, *_9$$8 = NULL, *_11$$9 = NULL, _12$$9 = zval_used_for_init, *_13$$9 = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("engines"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, ice_mvc_view_engine_php_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 128, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, ".phtml", 1);
		zephir_update_property_array(this_ptr, SL("engines"), _2$$3, _1$$3 TSRMLS_CC);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("engines"), PH_NOISY_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "ice/mvc/view.zep", 67);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(ext, _5, _4);
		ZEPHIR_GET_HVALUE(engine, _6);
		if (Z_TYPE_P(engine) == IS_OBJECT) {
			if (zephir_instance_of_ev(engine, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_7$$6);
				ZEPHIR_INIT_NVAR(_8$$6);
				zephir_create_array(_8$$6, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_8$$6, this_ptr);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_7$$6, engine, _8$$6);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("engines"), ext, _7$$6 TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(engine) == IS_STRING) {
				ZEPHIR_INIT_NVAR(_9$$8);
				ZEPHIR_INIT_NVAR(_10$$8);
				zephir_create_array(_10$$8, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(_10$$8, this_ptr);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(_9$$8, engine, _10$$8 TSRMLS_CC);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("engines"), ext, _9$$8 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_11$$9);
				object_init_ex(_11$$9, ice_exception_ce);
				ZEPHIR_SINIT_NVAR(_12$$9);
				ZVAL_STRING(&_12$$9, "Invalid template engine registration for '%s' extension", 0);
				ZEPHIR_CALL_FUNCTION(&_13$$9, "sprintf", &_14, 12, &_12$$9, ext);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _11$$9, "__construct", &_15, 13, _13$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11$$9, "ice/mvc/view.zep", 63 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_MEMBER(this_ptr, "engines");

}

/**
 * Try to render the view with vars for engines.
 *
 * @param string file
 * @param array data
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, render) {

	HashTable *_2, *_7$$5;
	HashPosition _1, _6$$5;
	zend_bool exists = 0, _15;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_13 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL, *ext = NULL, *engine = NULL, *engines = NULL, *path = NULL, *dir = NULL, *dirs = NULL, *content = NULL, *_0, **_3, *_14, *_4$$5 = NULL, **_8$$5, *_5$$7 = NULL, *_9$$8, *_11$$9 = NULL, *_16$$10, _17$$10, *_18$$10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = ZEPHIR_GLOBAL(global_null);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	exists = 0;
	ZEPHIR_INIT_VAR(content);
	ZVAL_NULL(content);
	if (Z_TYPE_P(file) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("file"), file TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(ice_exception_ce, "You must set the file to use within your view before rendering", "ice/mvc/view.zep", 89);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(engines, &_2, &_1, 0, 0, "ice/mvc/view.zep", 112);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(ext, _2, _1);
		ZEPHIR_GET_HVALUE(engine, _3);
		ZEPHIR_OBS_NVAR(_4$$5);
		zephir_read_property_this(&_4$$5, this_ptr, SL("viewsDir"), PH_NOISY_CC);
		if (Z_TYPE_P(_4$$5) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(dirs);
			zephir_read_property_this(&dirs, this_ptr, SL("viewsDir"), PH_NOISY_CC);
		} else {
			ZEPHIR_INIT_NVAR(dirs);
			zephir_create_array(dirs, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5$$7);
			zephir_read_property_this(&_5$$7, this_ptr, SL("viewsDir"), PH_NOISY_CC);
			zephir_array_fast_append(dirs, _5$$7);
		}
		zephir_is_iterable(dirs, &_7$$5, &_6$$5, 0, 0, "ice/mvc/view.zep", 110);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$5, (void**) &_8$$5, &_6$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$5, &_6$$5)
		) {
			ZEPHIR_GET_HVALUE(dir, _8$$5);
			_9$$8 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(path);
			ZEPHIR_CONCAT_VVV(path, dir, _9$$8, ext);
			if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
				exists = 1;
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", &_10, 0, data);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$9, this_ptr, "all", &_12, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&content, engine, "render", &_13, 0, path, _11$$9);
				zephir_check_call_status();
				break;
			}
		}
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("silent"), PH_NOISY_CC);
	_15 = !zephir_is_true(_14);
	if (_15) {
		_15 = !exists;
	}
	if (_15) {
		ZEPHIR_INIT_VAR(_16$$10);
		object_init_ex(_16$$10, ice_exception_ce);
		ZEPHIR_SINIT_VAR(_17$$10);
		ZVAL_STRING(&_17$$10, "The requested view %s could not be found", 0);
		ZEPHIR_CALL_FUNCTION(&_18$$10, "sprintf", NULL, 12, &_17$$10, path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _16$$10, "__construct", &_19, 13, _18$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_16$$10, "ice/mvc/view.zep", 113 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(content);

}

/**
 * Load the view.
 *
 * @param string file Name of file without extension from the views dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file_param = NULL, *data_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, file, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load the partial view.
 *
 * @param string file Name of file without extension from the partials dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, partial) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file_param = NULL, *data_param = NULL, *_0, *_1;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("partialsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, _1, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load the layout view.
 *
 * @param string file Name of file without extension from the layouts dir
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Ice_Mvc_View, layout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *file = NULL, *data_param = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		ZEPHIR_CPY_WRT(file, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}


	if (!(zephir_is_true(file))) {
		ZEPHIR_OBS_NVAR(file);
		zephir_read_property_this(&file, this_ptr, SL("mainView"), PH_NOISY_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("layoutsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, _1, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set var to the view.
 *
 * @param string name
 * @param mixed value
 */
PHP_METHOD(Ice_Mvc_View, setVar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set multiple vars to the view.
 *
 * @param array vars
 */
PHP_METHOD(Ice_Mvc_View, setVars) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL;
	zval *vars = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	vars = vars_param;


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, vars);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of the `setMainView` method.
 *
 * @param array vars
 */
PHP_METHOD(Ice_Mvc_View, setLayout) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *layout_param = NULL;
	zval *layout = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);

	zephir_get_strval(layout, layout_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmainview", NULL, 0, layout);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic toStrint, get the rendered view.
 */
PHP_METHOD(Ice_Mvc_View, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

