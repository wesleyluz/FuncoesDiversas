import {
    ScrollView,
    StyleSheet,
    Text,
    View

} from "react-native";
import React, {useState} from "react";
import {TextInput} from "../../components";
import {colors, commonStyles, fonts} from "../../styles";
import {useDispatch} from "react-redux";
import {DisabledButton} from "../../components/DisabledButton";

import { KeyboardAwareScrollView } from 'react-native-keyboard-aware-scroll-view'
import {hideError} from "../../redux/error/actions";

import PasswordEyeIcon from "../../components/PasswordEyeIcon";
import authService from "../../services/authService";
import ErrorMessageModal from "../../components/ErrorMessageModal";
import SuccessMessageModal from "../../components/SuccessMessageModal";
export default function NewPasswordScreen(props) {
    const {sender, username, email} = props.route?.params;

    const [continueDisabled, setContinueDisabled] = useState(true);
    const dispatch = useDispatch();
    const [showErrorAlert, setShowErrorAlert] = useState(false);
    const [error, setError] = useState('');
    const [showSuccessMessage, setShowSuccessMessage] = useState(false);
    const displayErrorMessage = () => {
        setError('You need to fill out at either username or email.')
    }

    const continueAction = () => {
       // props.navigation.navigate('PhoneAuth', {sender: 'Recovery', username: username, email: email});
        authService.changePassword(email, username, password).then(
            r => {
                setShowSuccessMessage(true);
            }
        ).catch(err => {
            setError(err);
            setShowErrorAlert(true);
        });
    }
    const [secureTextEntry, setSecureTextEntry] = useState(true);
    const [password, setPassword] = useState('');
    const [secureTextEntryConfirm, setSecureTextEntryConfirm] = useState(true);
    const [passwordConfirm, setPasswordConfirm] = useState('');
    const changePassword = (value) => {
        setPassword(value);
        validatePasswords(value, passwordConfirm);
    }
    const changePasswordConfirm = (value) => {
        setPasswordConfirm(value);
        validatePasswords(password, value);
    }

    const validatePasswords = (password, passwordConfirm) => {
        if (password.length < 6 && passwordConfirm.length < 6){
            setError('Password is too short!')
            setContinueDisabled(true);
        } else
        if (password !== passwordConfirm){
            setError('Passwords must match!');
            setContinueDisabled(true);
        } else {
            setError('');
            setContinueDisabled(false);
        }
    }
    const getSubmitButton = () => {
        return (
            <DisabledButton
                enabledAction={continueAction}
                disabledAction={() => displayErrorMessage()}
                enabledLabel='Continue'
                disabledLabel='Continue'
                isDisabled={continueDisabled}
                error={error}/>
        )
    }

    const hideErrorAction = () => {
        dispatch(hideError());
    }

    const onEyeClick = () => {
        if (secureTextEntry){
            setSecureTextEntry(false);
        } else setSecureTextEntry(true);
    }
    const onEyeClickConfirm = () => {
        if (secureTextEntryConfirm){
            setSecureTextEntryConfirm(false);
        } else setSecureTextEntryConfirm(true);
    }
    const closeErrorMessage = () => {
        setError('');
        setShowErrorAlert(false);

    }
    const confirmErrorMessage = () => {
        setError('');
        setShowErrorAlert(false);
        props.navigation.navigate('PasswordResetView', {sender: 'Login'});
    }
    const confirmMessageAction = () => {
        setShowSuccessMessage(false);
        props.navigation.navigate('Auth', {sender: 'recovery'});
    }


    return (
        <KeyboardAwareScrollView
            style={commonStyles.container}
            resetScrollToCoords={{ x: 0, y: 0 }}
        >
            <ScrollView
                style={styles.scrollStyle}
                contentContainerStyle={{paddingBottom: 30}}
            >
                <View style={commonStyles.screenSubtitleHeader}>
                    <Text style={commonStyles.screenSubtitleHeaderText}>Password Reset</Text>
                </View>
                <Text style={styles.additionalText}>
                    Enter a new password for your account:
                </Text>
                <View style={styles.passwordFieldView}>
                    <PasswordEyeIcon secureTextEntry={secureTextEntry} onEyeClick={onEyeClick} iconColor={colors.iconColor}/>
                    <TextInput
                        placeholder="Password"
                        secureTextEntry={secureTextEntry}
                        style={{...commonStyles.textInput, ...styles.passwordInput}}
                        value={password}
                        onFocus={() => hideErrorAction()}
                        onChangeText={value => changePassword(value)}
                    />
                </View>
                <TextInput style={styles.additionalText}>
                    Confirm Password
                </TextInput>
                <View style={styles.passwordFieldView}>
                    <PasswordEyeIcon secureTextEntry={secureTextEntryConfirm} onEyeClick={onEyeClickConfirm} iconColor={colors.iconColor}/>
                    <TextInput
                        placeholder="Confirm Password"
                        secureTextEntry={secureTextEntryConfirm}
                        style={{...commonStyles.textInput, ...styles.passwordInput}}
                        value={passwordConfirm}
                        onFocus={() => hideErrorAction()}
                        onChangeText={value => changePasswordConfirm(value)}
                    />
                </View>
               {getSubmitButton()}
                <ErrorMessageModal
                    title={'Password save error'}
                    description={error}
                    isVisible={showErrorAlert}
                    setVisible={setShowErrorAlert}
                    cancelTitle='Cancel'
                    cancelAction={()=> closeErrorMessage()}
                    mainTitle='Try Again'
                    mainAction={()=> confirmErrorMessage()}/>
                <SuccessMessageModal
                    title={'Password changed successfully.'}
                    description={'Use your new password to login to app.'}
                    isVisible={showSuccessMessage}
                    setVisible={setShowSuccessMessage}
                    confirmTitle='OK'
                    confirmAction={()=> confirmMessageAction()}/>

            </ScrollView>
        </KeyboardAwareScrollView>
    )

}
const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: 'white',
        padding: 10
    },
    scrollStyle: {
        padding: 5
    },
    pickupHeader: {
        paddingBottom: 0,
        flexDirection: 'row'
    },
    additionalText: {
        fontFamily: fonts.primaryRegular,
        fontSize: 14,
        color: '#a4a4a4',
        paddingTop: 10,
        marginTop: 10
    },

    dropdownContainer: {
        paddingBottom: 30,
        marginTop: 0
    },
    passwordContainer: {
        margin: 0,
        alignSelf: 'stretch',
        width: '100%'
    },
    passwordInput: {
        alignSelf: 'stretch',
        marginTop: 10
    },
    passwordFieldView: {
        alignSelf: 'stretch',
        justifyContent: 'center',
        alignItems: 'center',
        flexDirection: 'column'
    },

});
