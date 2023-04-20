import React from "react";

export class Modal extends React.Component<null, State>{

    constructor(props:null){
        super(props);
        this.state = {
        currentElement:null
        }
        window.modalComponent = this

    }
    public assignElement(element:JSX.Element){
        this.setState({
            currentElement:element
        })
    }
    public removeElement(){
        this.setState({
            currentElement:null
        })
    }
    render(): React.ReactNode {
        return(
            <div className={this.state.currentElement ? 'modal-full' : 'modal-hidden'}>
                {this.state.currentElement}
            </div>
        )
    }
}
type State = {
    currentElement: JSX.Element | null;
}
export function displayElementInModal(element:JSX.Element){
    window.modalComponent.assignElement(element)
}
export function removeElementFromModal(){
    window.modalComponent.removeElement()
}
declare global {
    interface Window {
        modalComponent:Modal;
    }
}
